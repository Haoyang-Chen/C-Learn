//
//  main.cpp
//  上机作业12.18(2
//
//  Created by Haoyang Chen on 2020/12/19.
//

#include <iostream>
#include <cmath>
using namespace std;
template<class T>
void sort(T com[],int n){
    for(int i=0;i<n;i++){
        for(int m=i+1;m<n;m++){
            if(com[m]>com[i]){
                T temp=com[i];
                com[i]=com[m];
                com[m]=temp;
            }
        }
    }
}
class Complex
{
    double re, im;
    double len;
public:
    Complex(Complex &c1){
        re=c1.re;
        im=c1.im;
        len=c1.calLen();
    }
    Complex(double r=0, double i=0)
    {
        re = r;
        im = i;
        len = calLen();
    }
    double calLen()     //求模长
    {
        return (sqrt(re*re + im*im));
    }
    bool operator>(Complex c2){
        if(len>c2.len){
            return 1;
        }else{
            return 0;
        }
    }
    void set(double d1,double d2){
        re=d1;
        im=d2;
        len=calLen();
    }
    void show(){
        cout << re<<"+i*"<<im<<endl;
    }
    Complex& operator=(Complex &c1){
        re=c1.re;
        im=c1.im;
        return *this;
    }
};
int main(int argc, const char * argv[]) {
    Complex c[5];
        double d1,d2;
        cout << "输入5个复数（实部 虚部）" << endl;
        for(int i = 0; i< 5; i++)
        {
            cout<<"输入实部和虚部：";
            cin>>d1>>d2;
            c[i].set(d1,d2);
        }
        sort(c, 5);
        cout << "排序后：" << endl;
        for(int i = 0; i< 5; i++)
            c[i].show();
        return 0;
    return 0;
}
