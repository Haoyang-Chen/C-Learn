//
//  main.cpp
//  上机作业11.27(2
//
//  Created by Haoyang Chen on 2020/11/26.
//

#include <iostream>
using namespace std;
int del(int r[],int n){
    int number,avg=0;
    for(int i=0;i<n;i++){
        avg+=r[i];
    }
    avg/=n;
    int counter=0;
    for(int i=0;i<n;i++){
        if(r[i]<avg){
            for(int m=2;m<r[i];m++){
                if(r[i]%m==0){
                    for(int a=i;a<n-1;a++){
                        r[a]=r[a+1];
                    }
                    counter++;
                    break;
                }
            }
        }
    }
    number=n-counter;
    return number;
}
int main(int argc, const char * argv[]) {
    int data[6]={17,5,6,18,8,28};
    int n=del(data,6);
    cout <<n<<endl;
    for(int i=0;i<n;i++){
        cout << data[i]<<" ";
    }
    return 0;
}
