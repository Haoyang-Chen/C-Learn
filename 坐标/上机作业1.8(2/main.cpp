//
//  main.cpp
//  上机作业1.8(2
//
//  Created by Haoyang Chen on 2021/1/8.
//

#include <iostream>
using namespace std;
class Point{
    int x,y;
public:
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
    void set_coor(int X,int Y){
        x=X;
        y=Y;
    }
    Point(){
        x=0;
        y=0;
    }
    Point(int X,int Y){
        set_coor(X, Y);
    }
    void Show(){
        cout<<"x="<<x<<"  "
        <<"y="<<y<<endl;
    }
};
class Rectangle:public Point{
    double width,length;
public:
    Rectangle(int X,int Y,double w,double l){
        set_coor(X, Y);
        width=w;
        length=l;
    }
    Rectangle(){
        set_coor(0, 0);
        width=1;
        length=1;
    }
    double cal_area(){
        return width*length;
    }
    void Show(){
        cout <<"point1:("<<get_x()<<","<<get_y()<<")"<<endl
             <<"point2:("<<get_x()+width<<","<<get_y()<<")"<<endl
             <<"point3:("<<get_x()+width<<","<<get_y()+length<<")"<<endl
             <<"point4:("<<get_x()<<","<<get_y()+length<<")"<<endl;
    }
    int position(Point & p){
        if(p.get_x()>this->get_x()&&
           p.get_y()>this->get_y()&&
           p.get_x()<this->get_x()+width&&
           p.get_y()<this->get_y()+length){
            return -1;
        }else
        if(p.get_x()<this->get_x()||
           p.get_y()<this->get_y()||
           p.get_x()>this->get_x()+width||
           p.get_y()>this->get_y()+length){
            return 1;
        }else{
            return 0;
        }
    }
};
int main(int argc, const char * argv[]) {
    Rectangle rt1(0,0,6,8),rt2,rt3(rt1);
        Point p1(0,0),p2(6,8),p3(3,3),p4(8,4),p5(8,8);
        
        rt1.Show();
        rt2.Show();
        cout<<"点p1:";
        p1.Show();
        cout<<"矩形rt3:"<<'\t';
        rt3.Show();
        switch(rt3.position(p1))
    {
        case 0:cout<<"在矩形上"<<endl;break;
        case -1:cout<<"在矩形内"<<endl;break;
        case 1:cout<<"在矩形外"<<endl;break;
        }

        cout<<"点p2:";
        p2.Show();
        cout<<"矩形rt3:"<<'\t';
        rt3.Show();
        switch(rt3.position(p2))
    {
        case 0:cout<<"在矩形上"<<endl;break;
        case -1:cout<<"在矩形内"<<endl;break;
        case 1:cout<<"在矩形外"<<endl;break;
        }

        cout<<"点p3:";
        p3.Show();
        cout<<"矩形rt3:"<<'\t';
        rt3.Show();
        switch(rt3.position(p3))
    {
        case 0:cout<<"在矩形上"<<endl;break;
        case -1:cout<<"在矩形内"<<endl;break;
        case 1:cout<<"在矩形外"<<endl;break;
        }

        cout<<"点p4:";
        p4.Show();
        cout<<"矩形rt3:"<<'\t';
        rt3.Show();
        switch(rt3.position(p4)){
        case 0:cout<<"在矩形上"<<endl;break;
        case -1:cout<<"在矩形内"<<endl;break;
        case 1:cout<<"在矩形外"<<endl;break;
        }

        cout<<"点p5:";
        p5.Show();
        cout<<"矩形rt3:"<<'\t';
        rt3.Show();
        switch(rt3.position(p5)){
        case 0:cout<<"在矩形上"<<endl;break;
        case -1:cout<<"在矩形内"<<endl;break;
        case 1:cout<<"在矩形外"<<endl;break;
        }
    return 0;
}
