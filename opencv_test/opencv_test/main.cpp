#include <core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <ostream>
#include <typeinfo>
#include <time.h>
using namespace std;
using namespace cv;
class Nnetwork{
public:
    int visibleSize, hiddenSize, outputSize, layer_num;
    double lambda, cost, a;
    Mat data;//input
    Mat pre_data;
    Mat pre_outp;
    Mat outp;//output
    Mat *b, *W, *bgrad, *Wgrad, *active_value, *test_Wgrad, *test_bgrad,*av;
    void initParam()//初始化神经网络参数
    {
        a = 0.2;
        b = new Mat[layer_num];
        W = new Mat[layer_num];
        b[0] = Mat(hiddenSize, 1, CV_64FC1, Scalar(0));
        b[layer_num - 1] = Mat(outputSize, 1, CV_64FC1, Scalar(0));
        W[0] = Mat(hiddenSize, visibleSize, CV_64FC1);
        W[layer_num - 1] = Mat(outputSize, hiddenSize, CV_64FC1);
        for (int i = 1; i < layer_num - 1; i++)
        {
            W[i] = Mat(hiddenSize, hiddenSize, CV_64FC1);
            b[i] = Mat(hiddenSize, 1, CV_64FC1, Scalar(0));
        }
        double r = sqrt(6) / sqrt(hiddenSize + visibleSize + 1);
        for (int i = 0; i < layer_num; i++)
        {
            randu(W[i], Scalar::all(0), Scalar::all(1));
            randu(b[i], Scalar::all(0), Scalar::all(1));
            W[i] = W[i] * 2 * r - r;
            b[i] = b[i] * 2 * r - r;
        }
 
        bgrad = new Mat[layer_num]; Wgrad = new Mat[layer_num];
        for (int i = 0; i < layer_num; i++)
        {
            bgrad[i] = Mat::zeros(b[i].size(),CV_64FC1);
            Wgrad[i] = Mat::zeros(W[i].size(), CV_64FC1);
        }
        cost = 0;
    }
    Nnetwork()//默认构造函数
    {
        //默认构造函数默认只有一个隐含层
        layer_num = 2;//输入+隐含层一共的层数，如果只有一个隐含层则值为2
        visibleSize = 3;
        hiddenSize = 3;
        outputSize = 1;
        lambda = 0.0001;
        initParam();
    }
    Nnetwork(int visiblesize, int hiddensize, int outpsize, int layernums, double lambda) ://含参构造函数
        visibleSize(visiblesize),
        hiddenSize(hiddensize),
        outputSize(outpsize),
        layer_num(layernums),
        lambda(lambda)
    {
        initParam();
    }
    Mat sigmoid(Mat matrix)//适用于矩阵的sigmoid函数
    {
        return 1.0 / (1.0 + mat_exp(-1 * matrix));
    }
    double sigmoid(double num)//适用于单个数的sigmoid函数
    {
        return 1.0 / (1.0 + exp(-1 * num));
    }
    Mat mat_exp(Mat r)//对矩阵所有元素的e的指数运算
    {
        Mat tmp = Mat(r.size(), CV_64FC1);
        for (int i = 0; i < r.rows; i++)
        {
            for (int j = 0; j < r.cols; j++)
            {
                tmp.at<double>(i, j) = exp(r.at<double>(i, j));
            }
        }
        return tmp;
    }
    Mat mat_log(Mat r)//对矩阵所有元素的对数运算
    {
        Mat tmp = Mat(r.size(),CV_64FC1);
        for (int i = 0; i < r.rows; i++)
        {
            for (int j = 0; j < r.cols; j++)
            {
                tmp.at<double>(i, j) = log(r.at<double>(i, j));
            }
        }
        return tmp;
    }
    void forward_propagation()//前向传播函数
    {
        int data_size = data.cols;
        delete[] active_value;
        active_value = new Mat[layer_num];
        for (int i = 0; i < layer_num; i++)
            active_value[i] = repeat(b[i], 1, data_size);
        active_value[0] = sigmoid(W[0] * data + active_value[0]);
        for (int i = 1; i < layer_num; i++)
            active_value[i] = sigmoid(W[i] * active_value[i - 1] + active_value[i]);
    }
    void showimage(Mat data,int pic_size,int num)//图像的呈现
    {
 
        if (data.empty()) return;
        Mat image = Mat::ones(num*pic_size, num*pic_size, CV_64FC1);
        int res = 0;
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                int c = 0;
                for (int r = pic_size * i; r<pic_size * i + pic_size; r++)
                {
                    for (int l = j * pic_size; l<pic_size * j + pic_size; l++)
                    {
                        image.at<double>(r, l) = data.at<double>(i * num + j, c++);
                    }
                }
            }
        }
        imshow("image", image.t());
        waitKey();
    }
    void test_readdata()//读入数据——Matlab中5000份400个输入的数据
    {
        char* path = "C:\\Users\\ACER\\Documents\\MATLAB\\dataset";
        ifstream is(path, ios::in | ios::binary);
 
        data = Mat(5000, 20 * 20, CV_64FC1);
 
        if (!is) {
            cout << "cannot open file: " << path << endl;
        }
        else {
            if (is) {
                double temp = 0;
                for (int i = 0; i <5000; ++i) {
                    Mat image = Mat::zeros(20, 20, CV_64FC1);
 
                    for (int r = 0; r < 20; ++r) {
                        for (int c = 0; c < 20; ++c) {
                            is.read((char*)&temp, sizeof(temp));
                            data.at<double>(i, r * 20 + c) = (double)temp;
                        }
                    }
                    cout << "read data : " << i << endl;
                }
            }
        }
        is.close();
        //showimage(data, 20,70);
    }
    void test_readlabel()//读入数据X对应的Y值（label）
    {
        int test[11];
        memset(test, 0, sizeof(test));
        char* path = "C:\\Users\\ACER\\Desktop\\train-labels-idx1-ubyte\\test";
        ifstream is(path, ios::in | ios::binary);
 
        vector<double> labels;
        outp = Mat(5000, 1, CV_64FC1);
        if (!is) {
            cout << "cannot open file: " << path << endl;
        }
        else {
            if (is) {
                cout << "read successful " << endl;
                unsigned char temp = 0;
                int size = sizeof(temp);
                for (int i = 0; i < 5000; ++i) {
                    is.read((char*)&temp, size);
                    labels.push_back((double)temp);
                    outp.at<double>(i, 0) = labels[i];
                    test[int(labels[i])]++;
                }
            }
        }
        is.close();
 
        for (int i = 1; i < 11; i++)
        {
            cout << i << " : " << test[i] << endl;
        }
    }
    void test_load_Param()//载入参数
    {
        char* path = "C:\\Users\\ACER\\Documents\\MATLAB\\param";
        ifstream is(path, ios::in | ios::binary);
 
        b = new Mat[2];
        W = new Mat[2];
        W[0] = Mat(25, 400, CV_64FC1);
        W[1] = Mat(10, 25, CV_64FC1);
        b[0] = Mat(25, 1, CV_64FC1);
        b[1] = Mat(10, 1, CV_64FC1);
        int index = 0;
        if (!is) {
            cout << "cannot open file: " << path << endl;
        }
        else {
            if (is) {
                double temp = 0;
                for (int r = 0; r < 25; r++)
                {
                    is.read((char*)&temp, sizeof(temp));
                    b[0].at<double>(r, 0) = double(temp);
                }
                for (int l = 0; l < 400; l++)
                {
                    for (int r = 0; r < 25; r++)
                    {
                        is.read((char*)&temp, sizeof(temp));
                        W[0].at<double>(r, l) = double(temp);
                    }
                }
                for (int r = 0; r < 10; r++)
                {
                    is.read((char*)&temp, sizeof(temp));
                    b[1].at<double>(r, 0) = double(temp);
                    //cout << double(temp);
                }
                for (int l = 0; l < 25; l++)
                {
                    for (int r = 0; r < 10; r++)
                    {
 
                        is.read((char*)&temp, sizeof(temp));
                        W[1].at<double>(r, l) = double(temp);
                    }
                }
 
            }
        }
        is.close();
    }
    void test_nncost_1()
    {
        //a1 = [ones(m, 1) X];
        //z1 = a1*Theta1';
        //    temp = sigmoid(z1);
        //a2 = [ones(m, 1), temp];
        //z2 = a2*Theta2';
        //    h = sigmoid(z2);
        //%计算初始J的值
        //for k = 1:num_labels
        //    yk = y == k;
        //hthetak = h(:, k);
        //Jk = 1 / m * sum(-yk.*log(hthetak) - (1 - yk).*log(1 - hthetak));
        //J = J + Jk;
        //end
        delete[]active_value;
        active_value = new Mat[2];
        int data_size = outp.rows;
        active_value[0] = repeat(b[0], 1, data_size);
        active_value[1] = repeat(b[1], 1, data_size);
        //cout << "sizeof av0 : " << active_value[0].size()<<endl;
        //cout << "sizeof av1 : " << active_value[1].size() << endl;
        //cout << "sizeof data : " << data.size() << endl;
        active_value[0] = sigmoid(W[0]*data.t()+active_value[0]);
        active_value[1] = sigmoid(W[1]*active_value[0] + active_value[1]);
        //cout << endl<<active_value[1].at<double>(5, 5);
        //for k = 1:num_labels
        //    yk = y == k;
        //hthetak = h(:, k);
        //Jk = 1 / m * sum(-yk.*log(hthetak) - (1 - yk).*log(1 - hthetak));
        //J = J + Jk;
        //end
        Mat yk = Mat::zeros(10, data_size, CV_64FC1);
        for (int i = 0; i < data_size; i++)
            yk.at<double>(int(outp.at<double>(i, 0))-1,i) = 1;
 
        double J = sum((-1 * yk).mul(mat_log(active_value[1])) - (1 - yk).mul(mat_log(1 - active_value[1])))[0]/data_size;
 
        //cout << "Cost at parameters (loaded from ex4weights)\n(this value should be about 0.287629)\n" << J<<endl;
 
        lambda = 1;
        J += lambda / 2 / data_size * (sum(W[0].mul(W[0]))[0] + sum(W[1].mul(W[1]))[0]);
        //cout << "Cost at parameters (loaded from ex4weights)\n(this value should be about 0.383770)\n" << J<<endl;
        cost = J;
        Mat delta3 = (active_value[1] - yk);
        Mat tem = (delta3.t()*W[1]).t();
        Mat delta2 = tem.mul(active_value[0]).mul(1 - active_value[0]);
 
        Wgrad[1] = delta3*active_value[0].t() / data_size + lambda*W[1] / data_size;
        Wgrad[0] = delta2*data / data_size + lambda*W[0] / data_size;
        bgrad[1] = Mat(delta3.rows, 1, CV_64FC1, Scalar::all(0));
        bgrad[0] = Mat(delta2.rows, 1, CV_64FC1, Scalar::all(0));
        reduce(delta3, bgrad[1], 1, 1);
        reduce(delta2, bgrad[0], 1, 1);
 
    }
    void test_nncost_2()
    {
        active_value = new Mat[2];
        int data_size = outp.rows;
        active_value[0] = repeat(b[0], 1, data_size);
        active_value[1] = repeat(b[1], 1, data_size);
        cout << "sizeof av0 : " << active_value[0].size() << endl;
        cout << "sizeof av1 : " << active_value[1].size() << endl;
        cout << "sizeof data : " << data.size() << endl;
        cout << "sizeof W[0] : " << W[0].size() << endl;
        cout << "sizeof W[1] : " << W[1].size() << endl;
        active_value[0] = sigmoid(W[0] * data.t() + active_value[0]);
        active_value[1] = sigmoid(W[1] * active_value[0] + active_value[1]);
        
        Mat yk = Mat::zeros(3, data_size, CV_64FC1);
        for (int i = 0; i < data_size; i++)
                yk.at<double>(int(outp.at<double>(i, 0)) - 1, i) = 1;
        //cout << mat_log(active_value[1]) << endl;
        double J = sum((-1 * yk).mul(mat_log(active_value[1])) - (1 - yk).mul(mat_log(1 - active_value[1])))[0] / data_size;
 
        cout << "Cost at parameters \n(this value should be about 2.10095)\n" << J << endl;
        cost = J;
        J += lambda / 2 / data_size * (sum(W[0].mul(W[0]))[0] + sum(W[1].mul(W[1]))[0]);
        cout << "Cost at parameters \n(this value should be about )\n" << 0.0151364*lambda<< J - cost << endl;
        cost = J;
 
        Mat delta3 = (active_value[1] - yk);
        Mat tem = (delta3.t()*W[1]).t();
        Mat delta2 = tem.mul(active_value[0]).mul(1 - active_value[0]);
 
        Wgrad[1] = delta3*active_value[0].t() / data_size +lambda*W[1]/data_size;
        Wgrad[0] = delta2*data / data_size + lambda*W[0]/data_size;
        bgrad[1] = Mat(delta3.rows, 1, CV_64FC1, Scalar::all(0));
        bgrad[0] = Mat(delta2.rows, 1, CV_64FC1, Scalar::all(0));
        reduce(delta3, bgrad[1], 1, 1);
        reduce(delta2, bgrad[0], 1, 1);
        //cout << Wgrad[0] << endl;
    }
    double test_nncost_3(int lambda,Mat *active_value,Mat *b, Mat *W)
    {
        active_value = new Mat[2];
        int data_size = outp.rows;
        active_value[0] = repeat(b[0], 1, data_size);
        active_value[1] = repeat(b[1], 1, data_size);
 
        active_value[0] = sigmoid(W[0] * data.t() + active_value[0]);
        active_value[1] = sigmoid(W[1] * active_value[0] + active_value[1]);
 
        Mat yk = Mat::zeros(3, data_size, CV_64FC1);
        for (int i = 0; i < data_size; i++)
            yk.at<double>(int(outp.at<double>(i, 0)) - 1, i) = 1;
        double J = sum((-1 * yk).mul(mat_log(active_value[1])) - (1 - yk).mul(mat_log(1 - active_value[1])))[0] / data_size;
        J += lambda / 2 / data_size * (sum(W[0].mul(W[0]))[0] + sum(W[1].mul(W[1]))[0]);
 
        return J;
    }
    Mat sigmoidGradient(Mat inp)//sigmoid函数的梯度
    {
        return sigmoid(inp).mul(1 - sigmoid(inp));
    }
    void writeMatToFile(cv::Mat& m, const char* filename)
    {
        std::ofstream fout(filename);
 
        if (!fout)
        {
            std::cout << "File Not Opened" << std::endl;
            return;
        }
 
        for (int i = 0; i<m.rows; i++)
        {
            for (int j = 0; j<m.cols; j++)
            {
                fout << m.at<double>(i, j) << "\t";
            }
            fout << std::endl;
        }
 
        fout.close();
    }
    void computeNumericalGradient()//计算数学上的梯度，用于梯度检验
    {
        double lambda = 0, e = 0.0001; int count = 0;
        Mat *WW, *bb, *ac;
        ac = new Mat[layer_num];
        WW = new Mat[layer_num];
        bb = new Mat[layer_num];
        test_bgrad = new Mat[layer_num];
        test_Wgrad = new Mat[layer_num];
        for (int i = 0; i < layer_num; i++)
        {
            WW[i] = W[i].clone();
            bb[i] = b[i].clone();
        }
        double diff1 = 0, diff2 = 0;
        for (int i = 0; i < layer_num; i++)
        {
            test_bgrad[i] = Mat(bgrad[i].size(), CV_64FC1);
            for (int j = 0; j < bb[i].rows; j++)
            {
                for (int k = 0; k < bb[i].cols; k++)
                {
                    bb[i].at<double>(j, k) += e;
                    double loss1 = test_nncost_3(lambda, ac, bb, WW);
                    bb[i].at<double>(j, k) -= 2*e;
                    double loss2 = test_nncost_3(lambda, ac, bb, WW);
                    bb[i].at<double>(j, k) += e;
                    test_bgrad[i].at<double>(j, k) = (loss1 - loss2) / 2 / e;
                }
            }
            diff1 = sum((test_bgrad[i] - bgrad[i]).mul(test_bgrad[i] - bgrad[i]))[0];
            diff2 = sum((test_bgrad[i] + bgrad[i]).mul(test_bgrad[i] + bgrad[i]))[0];
        }
        for (int i = 0; i < layer_num; i++)
        {
            test_Wgrad[i] = Mat(Wgrad[i].size(), CV_64FC1);
            for (int j = 0; j < WW[i].rows; j++)
            {
                for (int k = 0; k < WW[i].cols; k++)
                {
                    WW[i].at<double>(j, k) += e;
                    double loss1 = test_nncost_3(lambda, ac, bb, WW);
                    WW[i].at<double>(j, k) -= 2 * e;
                    double loss2 = test_nncost_3(lambda, ac, bb, WW);
                    WW[i].at<double>(j, k) += e;
                    test_Wgrad[i].at<double>(j, k) = (loss1 - loss2) / 2 / e;
                }
            }
            diff1 = sum((test_Wgrad[i] - Wgrad[i]).mul(test_Wgrad[i] - Wgrad[i]))[0];
            diff2 = sum((test_Wgrad[i] + Wgrad[i]).mul(test_Wgrad[i] + Wgrad[i]))[0];
        }
        cout << "diff is : " << sqrt(diff1 / diff2)<<endl;
 
    }
    Mat debugInitializeWeights(int fan_out, int fan_in)
    {
        Mat res = Mat::zeros(fan_out, fan_in + 1,CV_64FC1);
        int c = 1;
        for (int i = 0; i < res.cols; i++)
        {
            for (int j = 0; j < res.rows; j++)
            {
                res.at<double>(j, i) = sin(c++);
            }
        }
        return res / 10;
    }
    void checkNNGradients()//梯度检验
    {
        int input_layer_size = 3,hidden_layer_size = 5,num_labels = 3,m = 5;
        Mat Theta1 = debugInitializeWeights(hidden_layer_size, input_layer_size),//size 5*4
            Theta2 = debugInitializeWeights(num_labels, hidden_layer_size),//3*6
            X = debugInitializeWeights(m, input_layer_size - 1),//5*3
            y = Mat(m, 1, CV_64FC1);
        for (int i = 1; i <= m; i++)
        {
            y.at<double>(i - 1, 0) = i%num_labels+1;
        }
        //cout << y;
        Nnetwork checknn(input_layer_size, hidden_layer_size, num_labels, 2,lambda);
        checknn.data = X;
        checknn.outp = y;
        checknn.W[0] = Mat::zeros(hidden_layer_size, input_layer_size, CV_64FC1);//5*3
        checknn.W[1] = Mat(num_labels, hidden_layer_size, CV_64FC1);//3*5
        checknn.b[0] = Mat(hidden_layer_size, 1, CV_64FC1);//5*1
        checknn.b[1] = Mat(num_labels, 1, CV_64FC1);//3*1
        for (int i = 0; i < Theta1.rows; i++)
            for (int j = 1; j < Theta1.cols; j++)
                checknn.W[0].at<double>(i, j-1) = Theta1.at<double>(i,j);
        for (int j = 0; j < Theta1.rows; j++)
            checknn.b[0].at<double>(j, 0) = Theta1.at<double>(j, 0);
        for (int i = 0; i < Theta2.rows; i++)
            for (int j = 1; j < Theta2.cols; j++)
                checknn.W[1].at<double>(i, j - 1) = Theta2.at<double>(i, j);
        for (int j = 0; j < Theta2.rows; j++)
            checknn.b[1].at<double>(j, 0) = Theta1.at<double>(j, 0);
 
 
 
        checknn.test_nncost_2();
        checknn.computeNumericalGradient();
        
    }
    void train()//训练
    {
        a=cost<1?0.1:0.2;//step
        test_nncost_1();
        for (int i = 0; i < layer_num; i++)
        {
            W[i] = W[i] - Wgrad[i] * a;
            b[i] = b[i] - bgrad[i] * a;
        }
        cout << "cost is " << cost << "   precise is "<<pre_dict()*100<<"%";
    }
    double predict()//给出神经网络的预测
    {
        double count = 0;
        for (int i = 0; i < active_value[1].cols; i++)
        {
            double max = 0; int index ;
            for (int j = 0; j < active_value[1].rows; j++)
            {
                if (active_value[1].at<double>(j,i)>max)
                {
                    index = j;
                    max = active_value[1].at<double>(j,i);
                }
            }
            if (index == int(outp.at<double>(i, 0) - 1)) ++count;
        }
        return count / active_value[1].cols;
    }
    double pre_dict()
    {
        delete[]av;
        av = new Mat[2];
        int data_size = pre_outp.rows;
        av[0] = repeat(b[0], 1, data_size);
        av[1] = repeat(b[1], 1, data_size);
        av[0] = sigmoid(W[0] * pre_data.t() + av[0]);
        av[1] = sigmoid(W[1] * av[0] + av[1]);
        double count = 0;
        for (int i = 0; i < av[1].cols; i++)
        {
            double max = 0; int index;
            for (int j = 0; j < av[1].rows; j++)
            {
                if (av[1].at<double>(j, i)>max)
                {
                    index = j;
                    max = av[1].at<double>(j, i);
                }
            }
            if (index == int(pre_outp.at<double>(i, 0) - 1)) ++count;
        }
        return count / av[1].cols;
    }
    void before_train()
    {
        Mat train_data = Mat(4000, 400, CV_64FC1);
        Mat train_outp = Mat(4000, 1, CV_64FC1);
        int c = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = i * 500; j < i * 500 + 400; j++)
            {
                for (int k = 0; k < 400; k++)
                {
                    train_data.at<double>(c, k) = data.at<double>(j, k);
                }
                train_outp.at<double>(c++, 0) = outp.at<double>(j, 0);
 
            }
        }
        c = 0;
        pre_data = Mat(1000, 400, CV_64FC1);
        pre_outp = Mat(1000, 1, CV_64FC1);
        for (int i = 0; i < 10; i++)
        {
            for (int j = i * 500 + 400; j < i * 500 + 500; j++)
            {
                for (int k = 0; k < 400; k++)
                {
                    pre_data.at<double>(c, k) = data.at<double>(j, k);
                }
                pre_outp.at<double>(c++, 0) = outp.at<double>(j, 0);
                
            }
        }
        data = train_data;
        outp = train_outp;
    }
};
 
int main()
{
    Nnetwork tt(400,25,10,2,3);
    //step_1:Loading and Visualizing Data
 
    tt.test_readdata();
    tt.test_readlabel();
    tt.showimage(tt.data, 20, 70);
    {
        //step_2:Loading Parameters
        tt.test_load_Param();
 
        //step_3:Compute Cost (Feedforward)
        tt.test_nncost_1();
        //step_4:Implement Regularization
        //step_5:Sigmoid Gradient
 
        //step_6:Initializing Pameters
        tt.initParam();
        //step_7:Implement Backpropagation
        tt.lambda = 0;
        tt.checkNNGradients();
        //step_8:Implement Regularization
        tt.lambda = 1;
        tt.checkNNGradients();
    }
    //step_9:Training NN
 
    tt.initParam();
    tt.before_train();
    int it = 2500, i = it;
 
 
    cout << endl<< "计时开始" << endl;
 
    clock_t start, finish;
    double totaltime;
    start = clock();
 
    //耗时代码
    Mat A = Mat(100, 100, CV_64FC1, Scalar::all(1.1)),
        B = Mat(100, 100, CV_64FC1, Scalar::all(1.1));
    while (i--)
    {
        cout << endl << "iter " << it - i << " : ";
        tt.train();
        //A *= B;
    }
    finish = clock();
    totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
}



