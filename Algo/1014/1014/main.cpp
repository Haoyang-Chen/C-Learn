//
//  main.cpp
//  1014
//
//  Created by Haoyang Chen on 2022/4/29.
//

#include <iostream>
using namespace std;

int cross_sum(int *nums,int start,int mid,int end){
    int left_sum,right_sum;
    left_sum=-1000;
    right_sum=-1000;
    int temp=0;
    for (int i=mid;i>=start;i--){
        temp+=nums[i];
        if (left_sum<temp)
            left_sum=temp;
    }
    temp=0;
    for (int i=mid+1;i<=end;i++){
        temp+=nums[i];
        if(right_sum<temp)
            right_sum=temp;
    }
    return left_sum+right_sum;
}

int find_(int *nums,int start, int end){
    if (start==end)
        return nums[start];
    int left_sum,right_sum,mid_sum;
    int mid=(start+end)/2;
    left_sum=find_(nums, start,mid);
    right_sum=find_(nums,mid+1,end);
    mid_sum=cross_sum(nums,start,mid,end);
    if (left_sum>=right_sum && left_sum>=mid_sum)
        return left_sum;
    else if (right_sum>=left_sum && right_sum>=mid_sum)
        return right_sum;
    else
        return mid_sum;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n;
        cin >> n;
        int nums[n];
        for (int i=0;i<n;i++)
            cin >> nums[i];
        cout<<find_(nums,0,n-1)<<endl;
    }
    return 0;
}
