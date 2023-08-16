//
//  main.cpp
//  1026
//
//  Created by Haoyang Chen on 2022/5/13.
//

#include <iostream>
#include <math.h>
using namespace std;

void calc(int *nums,int n,int m){
    long long dp[n+1][m+1];
    int num[n+1][n+1];
    for (int i=1;i<=n;i++){
        int sum=0;
        for (int j=i;j<=n;j++){
            sum+=nums[j];
            num[i][j]=sum;
        }
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=0;
    for(int i=1;i<=n;i++)
        dp[i][0]=num[1][i];
    for(int i=2;i<=n;i++){
        for (int j=1;j<=min(i-1,m);j++){
            for(int k=2;k<=i;k++){
                dp[i][j]=max(dp[i][j],dp[k-1][j-1]*num[k][i]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for(int i=0;i<iter;i++){
        int n,m;
        cin >> n >> m;
        int nums[n+1];
        for (int i=1;i<=n;i++)
            cin >> nums[i];
        calc(nums,n,m);
    }
    return 0;
}
