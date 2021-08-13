//
//  main.cpp
//  上机作业12.11(1
//
//  Created by Haoyang Chen on 2020/12/11.
//

#include <iostream>
#include <iomanip>
using namespace std;
void inverse(int *p_matrix,int *p_middle,int row,int col){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            *(p_middle+i+j*row) = *(p_matrix+j+i*col);
        }
    }
}
void multiple(int *p_matrix1,int *p_matrix2,int *p_result,int row1,int col1,int col2){
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            for(int m=0;m<col1;m++){
                *(p_result+i*col2+j) += *(p_matrix1+i*row1+m)*(*(p_matrix2+m*col1+j));
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int middle[6][3],result[6][4];//middle:6X3  result:6X4
    int *p_mid,*p_res;
    p_mid = &middle[0][0];
    p_res = &result[0][0];
    int matrix1[3][6]={8,10,12,23,1,3,5,7,9,2,4,6,34,45,56,2,4,6};//1:3X6
    int matrix2[3][4]={3,2,1,0,-1,-2,9,8,7,6,5,4};//2:3X4
    int *p_mat1,*p_mat2;
    p_mat1 = &matrix1[0][0];
    p_mat2 = &matrix2[0][0];
    inverse(p_mat1, p_mid, 3, 6);
    multiple(p_mid,p_mat2 , p_res, 6, 3, 4);
    int m=0,n=0;
    for (int i = 0; i <6; i++){
         for(int j=0;j<3;j++)
         {
             cout<<setw(10)<<middle[i][j];
             n=n+1;
              if(n%3==0)
             cout<<endl;
         }
    }
    for (int x = 0; x <6; x++){
         for(int y=0;y<4;y++)
         {
             cout<<setw(10)<<result[x][y];
             m=m+1;
              if(m%4==0)
             cout<<endl;
         }
    }
    return 0;
}
