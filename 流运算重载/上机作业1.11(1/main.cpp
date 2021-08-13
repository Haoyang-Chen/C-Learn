//
//  main.cpp
//  上机作业1.11(1
//
//  Created by Haoyang Chen on 2021/1/11.
//

#include <iostream>
using namespace std;
class Complex{
    friend ostream &operator<<(ostream &b,Complex &a);
    friend istream &operator>>(istream &b,Complex &a);
    float real,image;
public:
    Complex(float r=0,float a=0){
        real=r;
        image=a;
    }
};
ostream &operator<<(ostream &b,Complex &a){
    return b<<a.real<<" + "<<a.image<<" i ";
}
istream &operator>>(istream &b,Complex &a){
    double re=0,im=0;
    char c=0;
    b>>c;
    if(c=='('){
        b>>re>>c;
        if(c==',') b>>im>>c;
        if(c==')') b.clear(ios::failbit);
    }
    else{
        b.putback(c);
        b>>c;
    }
    if(b)a=Complex(re,im);
    return b;
}
int main(int argc, const char * argv[]) {
    Complex a(1,2);
    cout << a;
    cin>>a;
    cout << a;
    return 0;
}
