//
//  main.cpp
//  1019
//
//  Created by Haoyang Chen on 2022/5/6.
//

#include <iostream>
#include <math.h>
using namespace std;

void bag(int *mass,int *value,int c,int n){
    int dp[c+1][n+1];
    for(int i=0;i<=c;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=0;
    for (int i=0;i<=c;i++){
        for (int j=1;j<=n;j++){
            if (mass[j-1]>i){
                dp[i][j]=dp[i][j-1];
                continue;
            }
            dp[i][j]=max(dp[i][j-1],dp[i-mass[j-1]][j-1]+value[j-1]);
        }
    }
    cout<<dp[c][n]<<endl;
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
