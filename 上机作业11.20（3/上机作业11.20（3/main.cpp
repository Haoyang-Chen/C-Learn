//
//  main.cpp
//  上机作业11.20（3
//
//  Created by Haoyang Chen on 2020/11/20.
//

#include <iostream>
using namespace std;
class MyTime{
    int hh,mm,ss;
public:
    MyTime(int a,int b,int c){
        hh=a;
        mm=b;
        ss=c;
    }
    MyTime(){
        hh=0;
        mm=0;
        ss=0;
    }
    MyTime operator+(MyTime m){
        MyTime temp(hh,mm,ss);
        temp.hh=hh+m.hh;
        temp.mm=mm+m.mm;
        temp.ss=ss+m.ss;
        if (temp.ss>=60){
            temp.ss-=60;
            temp.ss+=1;
        }
        if (temp.mm>=60){
            temp.mm-=60;
            temp.hh+=1;
        }
        if (temp.hh>=24){
            temp.hh-=24;
        }
        return temp;
    }
    MyTime operator-(MyTime m){
        MyTime temp(hh,mm,ss);
        temp.hh=hh-m.hh;
        temp.mm=mm-m.mm;
        temp.ss=ss-m.ss;
        if (temp.ss<0){
            temp.ss*=-1;
            temp.ss-=1;
        }
        if (temp.mm<0){
            temp.mm*=-1;
            temp.hh-=1;
        }
        if (temp.hh<0){
            temp.hh=24+(-1)*temp.hh;
        }
        return temp;
    }
    MyTime operator+=(MyTime m){
        MyTime temp(hh,mm,ss);
        hh+=m.hh;
        mm+=m.mm;
        ss+=m.ss;
        if (ss>=60){
            ss-=60;
            ss+=1;
        }
        if (mm>=60){
            mm-=60;
            hh+=1;
        }
        if (hh>=24){
            hh-=24;
        }
        return temp;
    }
    MyTime operator++(){
        ss++;
        if(ss==60){
            mm++;
            ss=0;
        }
        if(mm==60){
            hh++;
            mm=0;
        }
        return MyTime(hh,mm,ss);
    }
    MyTime operator++(int){
        MyTime t(hh,mm,ss);
        ss++;
        if(ss==60){
            mm++;
            ss=0;
        }
        if(mm==60){
            hh++;
            mm=0;
        }
        return t;
    }
    void print (){
        cout << hh<<":"<<mm<<":"<<ss<<endl;
    }
};
int main(int argc, const char * argv[]) {
    MyTime t1(1,1,1),t2(22,33,44),t3,t4;
    t3=t1+t2;
    t3.print();
    t4=t1-t2;
    t4.print();
    t1++;
    t1.print();
    ++t2;
    t2.print();
    return 0;
}
