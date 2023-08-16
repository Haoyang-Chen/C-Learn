//
//  main.cpp
//  1018
//
//  Created by Haoyang Chen on 2022/5/6.
//

#include <iostream>
#include <math.h>
using namespace std;

void bag(int *mass,int *value,int c,int n){
    int dp[c+1];
    for (int i=1;i<=c;i++)
        dp[i]=-1;
    dp[0]=0;
    int temp=0;
    for (int i=0;i<n;i++){
        for(int j=c;j>=mass[i];j--){
            if(dp[j-mass[i]]==-1)
                temp=-1;
            else
                temp=dp[j-mass[i]]+value[i];
            dp[j]=max(dp[j],temp);
        }
    }
    if (dp[c]==-1)
        dp[c]=0;
    cout<<dp[c]<<endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n,c;
        cin >>n;
        cin >>c;
        int value[n];
        int mass[n];
        for (int i=0;i<n;i++){
            cin >>mass[i];
            cin >>value[i];
        }
        bag(mass,value,c,n);
    }
    return 0;
}
