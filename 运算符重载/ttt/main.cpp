//
//  main.cpp
//  ttt
//
//  Created by Haoyang Chen on 2020/11/19.
//

#include <iostream>
using namespace std;
class test {
private:
    int a,b,c;
public:
    test(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    test operator+(test p1){
        test temp;
        a=a+p1.a;
        b=b+p1.b;
        c=c+p1.c;
        return temp;
    }
    test operator=(test p1){
        test temp;
        temp.a=p1.a;
        temp.b=p1.b;
        temp.c=p1.c;
        return temp;
    }
    test(){
        a=0;
        b=0;
        c=0;
    }
    void show(test p1){
        cout <<" a=" << p1.a << " b="<< p1.b<< " c="<< p1.c<<endl;
    }
};
int main(int argc, const char * argv[]) {
    test t1(1,1,1),t2(2,2,2);
    t1 = t1+t2;
    t1.show(t1);
    return 0;
}

