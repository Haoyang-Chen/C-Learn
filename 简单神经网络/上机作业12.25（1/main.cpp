//
//  main.cpp
//  上机作业12.25（1
//
//  Created by Haoyang Chen on 2020/12/25.
//

#include <iostream>
#include <math.h>
using namespace std;
class NN{
    float x[5],w[5],dt;
    double y;
public:
    NN(double t[],double d){
        for(int i=0;i<5;i++){
            this->w[i]=t[i];
            this->dt=d;
        }
    }
    void fun(double t[]){
        for(int i=0;i<5;i++){
            this->x[i]=t[i];
        }
        double result=0;
        for(int i=0;i<5;i++){
            result+=(x[i]-w[i])*(x[i]-w[i]);
        }
        this->y=exp((-1/(2*dt*dt))*result);
    }
    void print( ){
        cout <<"输入信号："<<endl;
        for(int i=0;i<5;i++){
            cout <<x[i]<<" ";
        }
        cout <<endl;
        cout <<"输出信号: "<<y<<endl;
    }
};

int main(){
    double a[5]={1.2,3.5,2.3,3.2,2.8};
    double b[5]={0.5,0.8,1.2,1.8,1.1};
    NN t(b,0.2);
    t.fun(a);
    t.print();
    return 0;
}
