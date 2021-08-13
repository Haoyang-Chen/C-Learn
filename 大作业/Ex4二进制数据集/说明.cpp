//dataset为5000*400的矩阵，元素类型为double
//手写数字的规模为20*20
//test中是数字对应的标签为5000*1的char类型

//头文件
#include <core/core.hpp>     
#include <iostream>  
#include <fstream>
#include <ostream>

using namespace std;
using namespace cv;
void main(){
//读取datasize并存入Mat data的代码如下：

		char* path = "C:\\Users\\ACER\\Documents\\MATLAB\\dataset";
		ifstream is(path, ios::in | ios::binary);

		Mat data = Mat(5000, 20 * 20, CV_64FC1);

		if (!is) {
			cout << "cannot open file: " << path << endl;
		}
		else {
			if (is) {
				double temp = 0;
				for (int i = 0; i <5000; ++i) {

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
//读取label并存入Mat outp中：

		char* path = "C:\\Users\\ACER\\Desktop\\train-labels-idx1-ubyte\\test";
		ifstream is(path, ios::in | ios::binary);
		Mat outp = Mat(5000, 1, CV_64FC1);
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
					outp.at<double>(i, 0) = labels[i];
				}
			}
		}
		is.close();

}