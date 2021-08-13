#include<iostream>
#include<iomanip>
using namespace std;

void inverse(int *p_matrix1,int *p_middle,int row1,int col1)
{
   int i,j;
   for (i=0;i<row1;i++)
      for (j=0;j<col1;j++)
         *(p_middle+j*row1+i)=*(p_matrix1+i*col1+j);
   return;
}
void mult(int *p_mid,int *p_mat2,int *p_res,int a,int b,int c)
{
    int i,j,k;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            *(p_res+i*b+j)=0;
            for(k=0;k<c;k++)
            {
                *(p_res+i*b+j)+=(*(p_mid+i*b+k))*(*(p_mat2+j*a+k));
            }
            
        }
    }
    return;
}
// 待改造的使用方法的示例请参照：

int main()
{
   int middle[6][3], result[6][4];
   int *p_mid,*p_res;
   int n=0,m=0;
   // 获得第一个二维数组元素首地址操作数组元素
   p_mid=&middle[0][0];
   p_res=&result[0][0];
   int matrix1[3][6]={8,10,12,23,1,3,5,7,9,2,4,6,34,45,56,2,4,6};
   int matrix2[3][4]={3,2,1,0,-1,-2,9,8,7,6,5,4};

   int *p_mat1,*p_mat2;
   p_mat1=&matrix1[0][0];
   p_mat2=&matrix2[0][0];

   inverse(p_mat1,p_mid,3,6);
   mult(p_mid,p_mat2,p_res,6,4,3);

   cout<<"转置后矩阵为"<<endl;
   for (int i = 0; i <6; i++)
        for(int j=0;j<3;j++)
        {
            cout<<setw(10)<<middle[i][j];
            n=n+1;
             if(n%3==0)
            cout<<endl;
        }
    cout<<"乘法运算后结果为"<<endl;
    for (int x = 0; x <6; x++)
        for(int y=0;y<4;y++)
        {
            cout<<setw(10)<<result[x][y];
            m=m+1;
             if(m%4==0)
            cout<<endl;
        }// 然后自行输出矩阵元素
   return 0;
}
