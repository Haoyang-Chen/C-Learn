//
//  main.cpp
//  上机作业1.8(1
//
//  Created by Haoyang Chen on 2021/1/8.
//

#include <iostream>
#include <cstring>
using namespace std;
class commodity{
public:
    commodity(){
        price=0;
        num=1;
        name="Null";
        manufac="Null";
    }
    commodity(int p,int n,string na,string m){
        price=p;
        num=n;
        name=na;
        manufac=m;
    }
    int price,num;
    string name,manufac;
};
class home_App:public commodity{
public:
    home_App(){
        price=0;
        num=1;
        name="Null";
        manufac="Null";
        power=0;
        color="Null";
    }
    home_App(int p,int n,string na,string m,int po,string c){
        price=p;
        num=n;
        name=na;
        manufac=m;
        power=po;
        color=c;
    }
    int power;
    string color;
};
class tV :public home_App{
public:
    tV(){
        price=0;
        num=1;
        name="Null";
        manufac="Null";
        power=0;
        color="Null";
        size=0;
        type="Null";
    }
    tV(int p,int n,string na,string m,int po,string c,int s,string t){
        price=p;
        num=n;
        name=na;
        manufac=m;
        power=po;
        color=c;
        size=s;
        type=t;
    }
    void show(){
        cout <<"price:"<<price<<endl
             <<"name:"<<name<<endl
             <<"manufactor:"<<manufac<<endl
             <<"pover:"<<power<<endl
             <<"color:"<<color<<endl
             <<"size:"<<size<<endl
             <<"type:"<<type<<endl;
    }
    int size;
    string type;
};
int main(int argc, const char * argv[]) {
    tV a(120,2,"V382","SONY",1200,"Black",64,"HDR");
    a.show();
    return 0;
}
