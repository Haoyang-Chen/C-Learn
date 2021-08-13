//
//  main.cpp
//  上机作业12.28(2
//
//  Created by Haoyang Chen on 2020/12/28.
//

#include<iostream>
using namespace std;
template <typename T>
class CMatrix
{
public:
    CMatrix(int rowsize = 0, int colsize = 0);   // 构造行数rowsize、列数colsize的矩阵
    ~CMatrix();                     // 析构函数
    void show(){
        for(int i=0;i<row_size;i++){
            for(int m=0;m<col_size;m++){
                cout << p_data[i][m]<<" ";
            }
            cout <<endl;
        }
    }
    void input(int i, int j, T value){  // value为输入的值T类型，i为行，j为列，把矩阵的i行，j列上的数据替换成 value;
        p_data[i][j]=value;
    }
protected:
   T**  p_data;    // 二级指针操作矩阵
   int  row_size;   // 行数
   int  col_size;    // 列数
};

template<typename T>
CMatrix<T> :: CMatrix(int rowsize, int colsize)
{
   row_size = rowsize;
   col_size = colsize;
   p_data = NULL;
    p_data = new T*[rowsize];
    for(int j=0;j<rowsize;j++){
        p_data[j]= new T[colsize];
    }
}

template<typename T>
CMatrix<T> :: ~CMatrix()                  //析构函数
{
    if(p_data!=NULL){
        delete [] this->p_data;
        this->p_data=NULL;
    }
}
using namespace std;
int main(int argc, const char * argv[]) {
    CMatrix<double> m1(2,2);  // 定义2*2浮点数矩阵

        int i,j,temp;

        cout << "输入2*2矩阵值:" << endl;
        for(i = 0; i < 2; i++)
            for(j = 0; j < 2; j++)
           {
                cin >> temp;
              m1.input(i,j,temp);
           }
        
            
    cout << "输出2*2矩阵值:" << endl;
    m1.show();
    return 0;
}
