//
//  main.cpp
//  上机作业11.20(2
//
//  Created by Haoyang Chen on 2020/11/20.
//

#include <iostream>
using namespace std;
class triangle{
private:
    float a,b,c;
    double size;
public:
    triangle(){
        a=6;b=8;c=10;
    }
    triangle(float a1,float b1,float c1){
        a=a1;
        b=b1;
        c=c1;
        float p=(a+b+c)/2;
        size = sqrt(p*(p-a)*(p-b)*(p-c));
    }
    triangle(triangle &A){
        a=A.a;
        b=A.b;
        c=A.c;
        size = A.size;
    }
    double Size(){
        float p=(a+b+c)/2;
        size = sqrt(p*(p-a)*(p-b)*(p-c));
        return size;
    }
    float operator+(triangle t){
        float a=size+t.size;
        return a;
    }
    float operator-(triangle t){
        float a=size-t.size;
        return a;
    }
//    triangle operator=(triangle t){
//        triangle temp(t.a,t.b,t.c);
//        return temp;
//    }
};
int main(int argc, const char * argv[]) {
    triangle t1(3,4,5),t2,t3(t1);
    t1.Size();
    cout << t1+t3 <<endl;
    cout << t1-t3 <<endl;
    return 0;
}
