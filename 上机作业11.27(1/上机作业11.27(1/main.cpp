//
//  main.cpp
//  上机作业11.27(1
//
//  Created by Haoyang Chen on 2020/11/26.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int data[10];
    printf("please enter the data\n");
    for(int i=0;i<9;i++){
        cin >> data[i];
    }
    int addition;
    printf("please enter the additonal number\n");
    cin >> addition;
//    int front =0;
//    int end =9;
    int position;
//    while(1){
//        if(data[(front+end)/2]>addition){
//            end=(front+end)/2;
//        }
//        else if(data[(front+end)/2]<addition){
//            front=(front+end)/2;
//        }else if(end<=front){
//            position=(front+end)/2;
//            break;
//        }
//    }
    for(int i=0;i<=8;i++){
        if(data[i]>addition){
            position=i;
            break;
        }
    }
    for(int i=8;i>=position;i--){
        data[i+1]=data[i];
    }
    data[position]=addition;
    for(int i=0;i<=9;i++){
        cout << data[i];
    }
    return 0;
}
