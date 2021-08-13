//
//  main.cpp
//  上机作业1.8(4
//
//  Created by Haoyang Chen on 2021/1/8.
//

#include <iostream>
using namespace std;
#define PI 3.14
class Geometric_shape{//几何图形
public:
    virtual double perimeter()
        {
            return 0;
            
        }    //周长
    virtual double area()
        {
            return 0;
            
        }    //面积
    virtual double volume()
        {
            return 0;
            
        }        //体积
    virtual void Show(){}
};

class Circle :public Geometric_shape{//圆
    double radius;
public:
    Circle()
        {
            radius = 0;
        }
    Circle(double vv)
        {
            radius = vv;
        }
    double perimeter()
        {
            return 2.0*PI*radius;
        }    //周长
    double area()
        {
            return PI*radius*radius;
        }        //面积
    double volume()
        {
            return 0;
        }        //体积
    void Show()
        {
            cout<<"radius="<<radius<<endl;
        }
    void set_radius(double rad){
        radius = rad;
    }
};
class cylinder:public Circle{
    double height;
public:
    cylinder()
        {
            height = 0;
        }
    cylinder(double vv,double rr)
        {
            height = vv;
            set_radius(rr);
        }
    double volume()
        {
            return area()*height;
        }
    void Show()
        {
            cout<<"height="<<height<<endl;
        }
    
};

void cal_volume(Geometric_shape &geo){
    cout << geo.volume()<<endl;
}

int main(int argc, const char * argv[]) {
    Geometric_shape* geo=NULL;
    Circle a(10);
    cylinder b(10,10);
    geo=&a;
    cal_volume(*geo);
    geo=&b;
    cal_volume(*geo);
    return 0;
}
