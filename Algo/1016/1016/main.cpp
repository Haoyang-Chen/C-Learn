//
//  main.cpp
//  1016
//
//  Created by Haoyang Chen on 2022/5/3.
//

#include <iostream>
using namespace std;
#define MAX 100000

void _find(int *nums,int target,int n){
    int dual[MAX];
    fill(dual, dual+MAX, 0);
    for (int i=0;i<n;i++){
        if (dual[target-nums[i]]==1||nums[i]==target){
            cout<<"yes"<<endl;
            return;
        }
        if (target-nums[i]>0)
            dual[nums[i]]=1;
    }
    cout<<"no"<<endl;
    return;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n,target;
        cin >> n;
        cin >> target;
        int nums[n];
        for(int j=0;j<n;j++){
            cin >> nums[j];
        }
        _find(nums,target,n);
    }
    return 0;
}
