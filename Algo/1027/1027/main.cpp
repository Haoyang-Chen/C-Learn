//
//  main.cpp
//  1027
//
//  Created by Haoyang Chen on 2022/5/17.
//

#include <iostream>
#include <limits.h>
using namespace std;

void sel(int n,int *si,int *fi,int *vi){
    int mins=INT_MAX,maxf=INT_MIN;
    for (int i=1;i<=n;i++){
        if (si[i]<mins)
            mins=si[i];
        if (fi[i]>maxf)
            maxf=fi[i];
    }
    int dp[maxf-mins+1];
    int res=0;
    for (int i=0;i<=maxf-mins;i++){
        dp[i]=0;
        for (int j=1;j<=n;j++){
            if (fi[j]<=mins+i && dp[i]<dp[si[j]-mins]+vi[j])
                dp[i]=dp[si[j]-mins]+vi[j];
        }
        if (dp[i]>res)
            res=dp[i];
    }
    cout << res << endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n;
        cin >> n;
        int si[10001],fi[10001],vi[10001];
        for (int i=1;i<=n;i++)
            cin >> si[i] >> fi[i] >> vi[i];
        sel(n,si,fi,vi);
    }
    return 0;
}
