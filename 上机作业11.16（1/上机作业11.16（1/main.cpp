//
//  main.cpp
//  上机作业11.16（1
//
//  Created by Haoyang Chen on 2020/11/16.
//

#include <iostream>
using namespace std;
class point{
public:
    int x,y;
    point(){
        x=0;
        y=0;
    };
    point (int a,int b){
        x=a;
        y=b;
    };
    void setpoint(int a , int b){
        x = a;
        y = b;
    }
};
class rect{
private:
    point p1,p2,p3,p4;
public:
    rect();
    rect(point p1,point p2){
        p1=p1;
        p2=p2;
    };
    rect(int a,int b,int c,int d){
        p1.x=a;
        p1.y=b;
        p3.x=c;
        p3.y=d;
        p2.x=c;
        p2.y=b;
        p4.x=a;
        p4.y=d;
    };
    void printp(){
        cout << "x1=" << p1.x <<"y1="<<p1.y<<"x2="<<p2.x<<"y2="<<p2.y<<"x3="<<p3.x<<"y3="<<p3.y<<"x4="<<p4.x<<"y4="<<p4.y<<endl;
    }
    int getarea(){
        return abs(p3.x-p1.x)*abs(p3.y-p1.y);
    }
    };
int main(int argc, const char * argv[]) {
    point p1(-15,56),p2(89,-10);
    point p3;
    rect r1(p1,p2);
    rect r2(1,5,5,1);
    cout << "the four points of r1's coordinates are " <<endl;
    r1.printp();
    cout << "the four points of r2's coordinates are " <<endl;
    r2.printp();
    cout << "the area of r2 is "<<r2.getarea()<<endl;
    return 0;
}
