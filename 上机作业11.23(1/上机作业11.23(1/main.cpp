//
//  main.cpp
//  上机作业11.23(1
//
//  Created by Haoyang Chen on 2020/11/23.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int A[10];
    for (int i=0;i<=9;i++){
        cin >> A[i];
    }
    for (int i=0;i<=9;i++){
        cout << A[i] ;
    }cout <<endl;
    int a=A[0];
    for(int i=0;i<=8;i++){
        if(A[i+1]>a&&A[i+1]%2==1){
            a=A[i+1];
        }
    }
    if(a%2==1){
        cout <<"the max of uneven number is:"<<a<<endl;
    }else{
        cout <<"uneven number doesnot exist"<<endl;
    }
    int b=A[0];
    for(int i=0;i<=8;i++){
        if(A[i+1]>b&&A[i+1]%2==0){
            b=A[i+1];
        }
    }
    if(b%2==0){
        cout <<"the max of even number is:"<<b<<endl;
    }else{
        cout <<"even number doesnot exist"<<endl;
    }
    return 0;
}
