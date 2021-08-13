//
//  main.cpp
//  上机作业11.30(2
//
//  Created by Haoyang Chen on 2020/11/30.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a[5]={1,3,6,7,9};
    int b[5]={2,4,5,8,10};
    int c[10];
    int t=0;
    int k=0;
    for(int i=0;i<10;i++){
        if(a[k]<=b[t]){
            c[i]=a[k];
            k++;
        }
        else {
            c[i]=b[t];
            t++;
        }
    }
    for(int i=0;i<10;i++){
        cout << c[i];
    }
    return 0;
}
