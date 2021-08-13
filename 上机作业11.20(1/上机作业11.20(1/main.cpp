//
//  main.cpp
//  上机作业11.20(1
//
//  Created by Haoyang Chen on 2020/11/20.
//

#include <iostream>
using namespace std;
class fraction{
    friend void exchange(fraction&a,fraction&b);
    int above,below;
public:
    fraction(){
        above=0;
        below=1;
    }
//    fraction(fraction &f1){
//        above=f1.above;
//        below=f1.below;
//    }
    fraction(int m,int n){
        above=m;
        below=n;
    }
    void reduction(fraction &f1){
        //cout <<"before reduction:"<<f1.above<<"/"<<f1.below<<endl;
        int a=1;
        for (int m=f1.above;m>=2;m--){
            if(f1.above%m==0&&f1.below%m==0){
                a=m;
                break;
            }
        }
        f1.above/=a;
        f1.below/=a;
        //cout <<"after reduction:"<<f1.above<<"/"<<f1.below<<endl;
    }
    void show(){
        cout <<above<<"/"<<below<<endl;
    }
    void makecommon(fraction &f1,fraction &f2){
        f1.reduction(f1);
        f2.reduction(f2);
        int a=0;
        for (int m=f1.below;;m++){
            if (m%f1.below==0&&m%f2.below==0){
                a=m;
                break;
            }
        }
        f1.above*=a/f1.below;
        f2.above*=a/f2.below;
        f1.below=a;
        f2.below=a;
    }
    fraction add(fraction f1,fraction f2){
        fraction temp;
        f1.makecommon(f1, f2);
        temp.above=f1.above+f2.above;
        temp.below=f1.below;
        temp.reduction(temp);
        f1.reduction(f1);
        f2.reduction(f2);
        cout << f1.above<<"/"<<f1.below<<"+"<<f2.above<<"/"<<f2.below<<"="<<temp.above<<"/"<<temp.below<<endl;
        return temp;
    }
    fraction subtract(fraction f1,fraction f2){
        fraction temp;
        f1.makecommon(f1, f2);
        temp.above=f1.above-f2.above;
        temp.below=f1.below;
        temp.reduction(temp);
        f1.reduction(f1);
        f2.reduction(f2);
        cout << f1.above<<"/"<<f1.below<<"-"<<f2.above<<"/"<<f2.below<<"="<<temp.above<<"/"<<temp.below<<endl;
        return temp;
    }
    void isequal(fraction f1,fraction f2){
        f1.reduction(f1);
        f2.reduction(f2);
        if(f1.above==f2.above&&f1.below==f2.below){
            cout <<"equal"<<endl;
        }else{
            cout <<"not equal"<<endl;
        }
    }
    fraction operator=(fraction f1){
        fraction temp(f1.above,f1.below);
        return temp;
    }
    fraction operator+(fraction f1){
        fraction temp;
        temp.above=above;
        temp.below=below;
        temp.makecommon(temp, f1);
        temp.above+=f1.above;
        temp.below+=f1.below;
        temp.reduction(temp);
        f1.reduction(f1);
        return temp;
    }
    fraction operator-(fraction f1){
        fraction temp;
        temp.above=above;
        temp.below=below;
        temp.makecommon(temp, f1);
        temp.above-=f1.above;
        temp.below-=f1.below;
        temp.reduction(temp);
        f1.reduction(f1);
        return temp;
    }
    bool operator==(fraction f1){
        bool m;
        fraction temp(above,below);
        f1.reduction(f1);
        temp.reduction(temp);
        if(f1.above==temp.above&&f1.below==temp.below){
            m=1;
        }else{
            m=0;
        }
        return m;
    }
};
void exchange(fraction&a,fraction&b){
    cout <<"before exchange"<<endl;
    a.show();
    b.show();
    fraction temp(a);
    a.above=b.above;
    a.below=b.below;
    b.above=temp.above;
    b.below=temp.below;
    cout <<"after exchange"<<endl;
    a.show();
    b.show();
}
int main(int argc, const char * argv[]) {
    fraction f1(1,3),f2,f3(f1),f4(2,4),f5;
    f4.reduction(f4);
    f3.show();
    f4.show();
    f1.add(f1, f4);
    f1.subtract(f1, f4);
    f1.isequal(f1, f3);
    f5=f1+f4;
    f5=f1-f4;
    f5.show();
    exchange(f1,f4);
    return 0;
}
