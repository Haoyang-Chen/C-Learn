//
//  main.cpp
//  上机作业1.8(3
//
//  Created by Haoyang Chen on 2021/1/8.
//

#include <iostream>
using namespace std;
class integer{
public:
    float a,b;
    int n;
    float step;
    float result;
    //virtual float integrate();
};
template<class T>
class rectangle:public integer{
public:
    float integrate(T A){
        result=0;
        for(float i=0;i<n;i++){
            result+=A.get(a+i*step);
        }
        result*=step;
        return result;
    }
    rectangle(float A,float B,int N){
        a=A;
        b=B;
        n=N;
        step=(b-a)/n;
        result =0;
    }
};
class Sin{
public:
    float get(float a){
        return sin(a);
    }
};
class Exp{
public:
    float get(float a){
        return exp(a);
    }
};
class func{
public:
    float get(float a){
        return 4.0/(1+a*a);
    }
};
int main(int argc, const char * argv[]) {
    Sin a;
    Exp b;
    func c;
    rectangle<Sin> A(0.0,3.14/2,1000);
    rectangle<Exp> B(0.0,1.0,1000);
    rectangle<func> C(0.0,1.0,1000);
    cout <<A.integrate(a)<<endl;
    cout <<B.integrate(b)<<endl;
    cout <<C.integrate(c)<<endl;
    return 0;
}
