//
//  main.cpp
//  上机作业12.21(2
//
//  Created by Haoyang Chen on 2020/12/21.
//

#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
class Integrate
{
    double a,b,dx;     //积分区间、等分区间的步长 dx=(b-a)/n
    int n;            //区间等分数
    double result;     //积分结果
    T cf;             //被积函数对象
public:
    Integrate(double aa=0, double bb=0, int nn=100)   //初始化积分区间和区间等分数
    {
        a=aa;//补充代码：
        b=bb;
        n=nn;
        dx=(b-a)/n;
        T cf;
    }
    void putlimits(double aa, double bb, int nn)  //修改积分区间和等分数
    {
    //补充代码：
        a=aa;
        b=bb;
        n=nn;
        dx=(b-a)/n;
    }
    void integrate();    //辛普森法计算积分
    void print()
    {
        cout << "result = " << result << endl;
    }
};

template<typename T>
void Integrate<T> :: integrate()
{
    double tempR=0;
    result = cf.f(a)+cf.f(b-dx);
    int m=0;
    for(int i=1;m<=n-1;i++){
        m=2*i-1;
//        T cf(a+(a-b)*m/n);
        tempR+=cf.f(a+m*dx);
    }
    tempR*=4;
    double tempR2=0;
    m=0;
    for(int i=1;m<=n-2;i++){
        m=2*i;
        tempR2+=cf.f(a+m*dx);
    }
    tempR2*=2;
    result=result+tempR+tempR2;
    result=result*dx/3;
    //补充代码：辛普森法计算定积分
}

class F1
{
public:
    //补充代码：封装被积函数（cosx）
//    F1(double X){
//        result =cos(X);
//    }
//    F1(){
//        result=0;
//    }
    double f(double a){
        return cos(a);
    }
};

int main()
{
    Integrate<F1> pf1(0.0, 3.1415/2, 1000);  // cosx在[0, pi/2]的定积分
    pf1.integrate();
    pf1.print();
    return 0;
}
