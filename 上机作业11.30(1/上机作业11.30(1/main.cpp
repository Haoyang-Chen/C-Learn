//
//  main.cpp
//  上机作业11.30(1
//
//  Created by Haoyang Chen on 2020/11/30.
//

#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
    double re,im;
    double len;
public:
    Complex(double r=0,double i=0){
        re = r;
        im = i;
        len = calLen();
    }
    double calLen(){
        float len;
        len = sqrt(re*re+im*im);
        return len;
    }
    void set(double d3,double d4){
        re=d3;
        im=d4;
    }
    bool operator<(Complex a){
        if(calLen()<a.calLen()){
            return false;
        }else if(calLen()>a.calLen()){
            return true;
        }
        return 0;
    }
    bool operator>(Complex a){
        if(calLen()>a.calLen()){
            return false;
        }else if(calLen()<a.calLen()){
            return true;
        }
        return 0;
    }
    bool operator=(Complex a){
        if (re==a.re&&im==a.im){
            return true;
        }else
        return false;
    }
    void show(){
        printf("the complex is %f %f\n",re,im);
    }
};
void Sort(Complex r[],int m){
    for(int a=0;a<m;a++)
    {
        for(int j=0; j < m-a-1;j++)
        {
            if(r[j] > r[j + 1])
            {
                Complex temp = r[j+1];
                r[j + 1] = r[j];
                r[j] = temp;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    Complex c[5];
    double d1,d2;
    cout << "please enter 5 complex (re&im) " <<endl;
    for(int i=0;i<5;i++){
        cout <<"enter the re & im " <<endl;
        cin >> d1 >> d2;
        c[i].set(d1,d2);
    }
    Sort(c, 5);
    cout << "after sortation "<< endl;
    for(int i=0;i<5;i++)
    c[i].show();
    return 0;
}
