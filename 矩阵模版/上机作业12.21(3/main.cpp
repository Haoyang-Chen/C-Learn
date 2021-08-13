//
//  main.cpp
//  上机作业12.21(3
//
//  Created by Haoyang Chen on 2020/12/21.
//

#include <iostream>
using namespace std;
template <class T, int max>
class CMatrix
{
public:
    T elems[max][max];
    int row;
    int col;
    CMatrix () {
        row=0; col=0;
        
    }
    ~ CMatrix (){
    };
    CMatrix (int r, int c)  {
        row=r;
        col=c;
        
    }
    T* operator[](int index){
        int i=index/row;
        int j=index%row;
        return &elems[i][j];
    }
    CMatrix <T, max>operator=( CMatrix <T,max>  temp){
        row=temp.row;
        col=temp.col;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                elems[i][j]=temp.elems[i][j];
            }
        }
        return *this;
    }
    void setdimension(int r, int c)
    {
        row=r; col=c;
    }
    void AddElem(T element,int i, int j){
        elems[i][j]=element;
    }
    void show(){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout << elems[i][j]<<" ";
            }
            cout << endl;
        }
    }
    CMatrix<T, max> inverse(){
        CMatrix result(col,row);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                result.elems[j][i]=elems[i][j];
            }
        }
        return result;
    }
    void findmax(){
        int location[2];
        for(int m=0;m<row;m++){
            for(int n=0;n<col-1;n++){
                if(elems[m][n]<elems[m][n+1]){
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
                        result.elems[m][n]+=elems[m][i]*mat2.elems[i][n];
                    }
                }
            }
        result.col=mat2.col;
        result.row=row;
        return result;
    }
    CMatrix operator+(CMatrix mat2){
        CMatrix result;
        for(int m=0;m<row;m++){
            for(int n=0;n<col;n++){
                result.elems[m][n]=elems[m][n]+mat2.elems[m][n];
            }
        }
        return result;
    }
};
int main()
{    CMatrix <int, 10> m1(3,5);
    for(int i=0; i<m1.row; i++)
        for(int j=0; j<m1.col; j++)
            m1.AddElem( i*j, i, j);
            m1.show();
    CMatrix <int, 10> m2;
            m2=m1.inverse();
    m2.show();
    m2[1][1]=100;
    m2.show();
    return 0;
}
