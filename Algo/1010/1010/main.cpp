//
//  main.cpp
//  1010
//
//  Created by Haoyang Chen on 2022/4/28.
//

#include <iostream>
#include <math.h>
using namespace std;

//int find(int * nums,float low, float high, int target){
//    int mid=ceil((low+high)/2);
//    if (nums[mid]==target){
//        return 1;
//    }
//    if (int(low)==int(high)){
//        return -1;
//    }
//    if (nums[mid]<target){
//        if (mid==low)
//            return -1;
//        if(find(nums,mid,high,target)==1){
//            cout << "success, father is "<<nums[mid]<<endl;
//            return 0;
//        }
//    }
//    if (nums[mid]>target){
//        if (mid==high)
//            return -1;
//        if(find(nums,low,mid,target)==1){
//            cout << "success, father is "<<nums[mid]<<endl;
//            return 0;
//        }
//    }
//    if (find(nums,low,mid,target)==-1||find(nums,mid,high,target)==-1)
//        cout<<"not found, father is "<<nums[mid]<<endl;
//    return -1;
//}

void find(int *nums, int n, int target){
    int low=0;
    int high=n-1;
    int mid=low+(high-low)/2;
    int parent=nums[mid];
    while(low<=high){
        mid=low +(high-low)/2;
        if (nums[mid]>target){
            high=mid-1;
            parent=nums[mid];
        }
        else if (nums[mid]<target){
            low=mid+1;
            parent=nums[mid];
        }else{
            cout << "success, father is " << parent << endl;
            return;
        }
    }
    cout << "not found, father is " << parent << endl;
    return;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i = 0; i < iter; i++){
        float len;
        cin >> len;
        int target;
        cin >> target;
        int nums[int(len)];
        for (int i=0;i<len;i++){
            cin >> nums[i];
        }
        find(nums,len, target);
    }
    return 0;
}
