//
//  main.cpp
//  1013
//
//  Created by Haoyang Chen on 2022/4/29.
//

#include <iostream>
using namespace std;

//void _pair(int * nums,int n){
//    int pair[n];
//    fill(pair, pair+n, 0);
//    for(int i=n-1;i>=0;i--){
//        for (int j=i;j<n;j++){
//            if(nums[i]>nums[j]){
//                pair[i]+=1;
//            }
//        }
//    }
//    int sum=0;
//    for (int i=0;i<n;i++)
//        sum+=pair[i];
//    cout << sum<<endl;
//}

int res;

void merge(int nums[],int start,int mid,int end){
    int i=start;
    int j=mid+1;
    int k=0;
    int temp[end-start+1];
    while (i<=mid&&j<=end){
        if (nums[i]<=nums[j])
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
    for (int i=0;i<end-start+1;i++)
        nums[start+i]=temp[i];
}

void merge_sort(int nums[],int start,int end){
    if (start<end){
        int mid=(start+end)/2;
        merge_sort(nums,start,mid);
        merge_sort(nums, mid+1, end);
        merge(nums,start,mid,end);
    }
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        res=0;
        int n;
        cin >> n;
        int nums[n];
        for (int i=0;i<n;i++)
            cin >>nums[i];
        merge_sort(nums,0,n-1);
        cout<<res<<endl;
    }
    return 0;
}
