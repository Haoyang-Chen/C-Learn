//
//  main.cpp
//  1017
//
//  Created by Haoyang Chen on 2022/5/3.
//

#include <iostream>
using namespace std;

int res;

void merge(int *nums,int start,int mid,int end){
    int temp[end-start+1];
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=end){
        if(nums[i]<=nums[j])
            temp[k++]=nums[i++];
        else{
            temp[k++]=nums[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid)
        temp[k++]=nums[i++];
    while(j<=end)
        temp[k++]=nums[j++];
    for (int q=0;q<end-start+1;q++)
        nums[start+q]=temp[q];
}

void merge_count(int *nums,int start,int end){
    int mid=(start+end)/2;
    if (start<end){
        merge_count(nums, start, mid);
        merge_count(nums, mid+1, end);
        merge(nums,start,mid,end);
    }
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for(int i=0;i<iter;i++){
        int n;
        cin >> n;
        int nums[n];
        for(int i=0;i<n;i++)
            cin >> nums[i];
        res=0;
        merge_count(nums, 0, n-1);
        cout<<res<<endl;
    }
    return 0;
}
