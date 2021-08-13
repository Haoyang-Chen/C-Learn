//
//  main.cpp
//  上机作业12.14(2
//
//  Created by Haoyang Chen on 2020/12/14.
//

#include <iostream>
#define max 50;
using namespace std;
class CMatrix{
public:
    int col,row;
    int mat[50][50];
    CMatrix(){
        row=5;
        col=5;
    }
    CMatrix(int r,int c){
        col=c;
        row=r;
    }
//    CMatrix(CMatrix &a){
//        this->row=a.row;
//        this->col=a.col;
//        for(int m=0;m<row;m++){
//            for(int n=0;n<col;n++){
//                mat[m][n]=a.mat[m][n];
//            }
//        }
//    }
    void SetElem(int element,int r,int c){
        mat[r][c]=element;
    }
    void show(){
        for(int m=0;m<row;m++){
            for(int n=0;n<col;n++){
                cout << mat[m][n]<<" ";
            }
            cout <<endl;
        }
    }
    CMatrix inverse(){
        CMatrix temp;
        temp.col=row;
        temp.row=col;
        for(int m=0;m<row;m++){
            for(int n=0;n<col;n++){
                temp.mat[n][m]=mat[m][n];
            }
        }
        return temp;
    }
    int GetElem(int r,int c){
        return mat[r][c];
    }
    CMatrix operator+(CMatrix mat2){
        CMatrix result;
        for(int m=0;m<row;m++){
            for(int n=0;n<col;n++){
                result.mat[m][n]=mat[m][n]+mat2.mat[m][n];
            }
        }
        return result;
    }
    CMatrix operator=(CMatrix mat2){
        row=mat2.row;
        col=mat2.col;
        for(int m=0;m<row;m++){
            for(int n=0;n<col;n++){
                mat[m][n]=mat2.mat[m][n];
                }
            }
        return *this;
    }
    void findmax(){
        int location[2];
        for(int m=0;m<row;m++){
            for(int n=0;n<col-1;n++){
                if(mat[m][n]<mat[m][n+1]){
                    location[0]=m;
                    location[1]=n+1;
                }
            }
        }
        cout << location[0]<<" "<<location[1]<<endl;
    }
    CMatrix operator*(CMatrix &mat2){
        CMatrix result;

            for(int m=0;m<row;m++){
                for(int n=0;n<mat2.col;n++){
                    for(int i=0;i<col;i++){
                        result.mat[m][n]+=mat[m][i]*mat2.mat[i][n];
                    }
                }
            }
        result.col=mat2.col;
        result.row=row;
        return result;
    }
};


int main(int argc, const char * argv[]) {
    CMatrix  m1(3,5);
        for(int i=0; i<m1.row; i++)
            for(int j=0; j<m1.col; j++)
                m1.SetElem( i*j, i, j);
        m1.show();
    CMatrix m2;
        m2 = m1.inverse();
        m2.show();
        m2.SetElem(100,0,0);
        m2.show();
    cout<<m2.GetElem(0,0)<<endl;;
    CMatrix m3;
    m3.show();
    m3=m2*m1;
    m3.show();
    return 0;
}
