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

    void test_nncost_1()
    {
        delete[]active_value;
        active_value = new Mat[2];
        int data_size = outp.rows;
        active_value[0] = repeat(b[0], 1, data_size);
        active_value[1] = repeat(b[1], 1, data_size);
        active_value[0] = sigmoid(W[0]*data.t()+active_value[0]);
        active_value[1] = sigmoid(W[1]*active_value[0] + active_value[1]);
        Mat yk = Mat::zeros(10, data_size, CV_64FC1);
        for (int i = 0; i < data_size; i++)
            yk.at<double>(int(outp.at<double>(i, 0))-1,i) = 1;
        double J = sum((-1 * yk).mul(mat_log(active_value[1])) - (1 - yk).mul(mat_log(1 - active_value[1])))[0]/data_size;
        lambda = 1;
        J += lambda / 2 / data_size * (sum(W[0].mul(W[0]))[0] + sum(W[1].mul(W[1]))[0]);
        cost = J;
        Mat delta3 = (active_value[1] - yk);
        Mat tem = (delta3.t()*W[1]).t();
        Mat delta2 = tem.mul(active_value[0]).mul(1 - active_value[0]);
 
        Wgrad[1] = delta3*active_value[0].t() / data_size + lambda*W[1] / data_size;
        Wgrad[0] = delta2*data / data_size + lambda*W[0] / data_size;
        bgrad[1] = Mat(delta3.rows, 1, CV_64FC1, Scalar::all(0));
        bgrad[0] = Mat(delta2.rows, 1, CV_64FC1, Scalar::all(0));
 
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


