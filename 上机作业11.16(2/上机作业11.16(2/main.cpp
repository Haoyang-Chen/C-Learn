//
//  main.cpp
//  上机作业11.16(2
//
//  Created by Haoyang Chen on 2020/11/16.
//

#include <iostream>
using namespace std;
class book{
private:
    int no,cap,lend;
    double price;
public:
    book(int a=0,int b=0,double c=0){
        no=a;
        cap=b;
        price=c;
        lend=0;
    }
    book(int a,int b,int c,double d){
        no=a;
        cap=b;
        lend=c;
        price=d;
    };
    int input(int m){
        while(1){
        if (m+cap>10){
            cout <<"full please enter another number"<<endl;
        }else
            cap+=m;
            break;
        }
        return 10-cap;
    }
    void lendout(int m){
        if (m<=cap){
            cout <<"successfully lent" <<endl;
            cap-=m;
            lend+=m;
        }else
            cout << "there is not enough books to lend"<<endl;
    }
    void giveback(int m){
        if (m+cap>10){
            cout <<"too much" <<endl;
        }else{
            cout <<"successfully returned" <<endl;
            cap+=m;
            lend-=m;
        }
    }
    int getcap(){
        return cap;
    }
    int getlend(){
        return lend;
    }
    double getprice(){
        return price;
    }
    void display(){
        cout <<"No:"<<no<<" remaining:"<<cap<<" price:"<<price<<" lent:"<<lend<<endl;
    }
};
int main(int argc, const char * argv[]) {
    book A(101,2,35,8);
    book B(102,5,66,2);
    A.input(3);
    B.input(8);
    int m;
    cin >>m;
    B.input(m);
    A.display();
    B.display();
    if (A.getprice()>B.getprice()){
        A.lendout(3);
    }else
        B.lendout(8);
    A.display();
    B.display();
    A.giveback(2);
    B.giveback(2);
    cout << "the total amount is "<<A.getcap()+B.getcap()<<endl;
    return 0;
}
