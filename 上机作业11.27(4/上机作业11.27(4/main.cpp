//
//  main.cpp
//  上机作业11.27(4
//
//  Created by Haoyang Chen on 2020/11/27.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int test[10]={0,1,2,3,4,5,6,7,8,9};
    int num;
    cout <<"enter the number"<<endl;
    cin >> num;
    int start=0;
    int end=9;
    while(start<=end){
        int middle=(start+end)/2;
        if(test[middle]>num){
            end=middle-1;
        }
        else if(test[middle]<num){
            start=middle+1;
        }else if(test[middle]==num){
            cout << "located at "<<middle<<endl;break;
        }
        if(start>end){
            cout << "DNE"<<endl;break;
        }
    }
    return 0;
}
