//
//  main.cpp
//  1028
//
//  Created by Haoyang Chen on 2022/5/17.
//

#include <iostream>
#include <limits.h>
using namespace std;

void dijkstra(int n,int m,int s,int f,int *si,int *fi,int *vi){
    int map[501][501];
    
    for(int i=0;i<501;i++)
        for(int j=0;j<501;j++)
            map[i][j]=INT_MAX;
    
    for(int i=0;i<m;i++)
        if(map[si[i]][fi[i]]>vi[i]){
            map[si[i]][fi[i]]=vi[i];
            map[fi[i]][si[i]]=vi[i];
        }
    
    for (int i=0;i<=n;i++)
        map[i][i]=0;
    
    int dp[501];
    fill(dp, dp+501, INT_MAX);
    bool fixed[501];
    
    fill(fixed, fixed+501, false);
    
    fixed[s]=true;
    for (int i=1;i<=n;i++)
            dp[i]=map[s][i];
    
    int idx=1;
    
    for(int k=1;k<n;k++){
        int minn=INT_MAX;
        for (int i =1;i<=n;i++){
            if (!fixed[i] && dp[i]<minn){
                minn=dp[i];
                idx=i;
            }
        }
        fixed[idx]=true;
        for (int i=1;i<=n;i++)
            if (map[idx][i]<INT_MAX)
                dp[i]=min(dp[i],dp[idx]+map[idx][i]);
    }
    if (dp[f]>=INT_MAX)
        dp[f]=-1;
    cout << dp[f] << endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n,m,s,f;
        cin >> n >> m >> s >> f;
        int si[m],fi[m],vi[m];
        for (int i=0;i<m;i++)
            cin >> si[i] >> fi[i] >> vi[i];
        dijkstra(n, m, s, f, si, fi, vi);
    }
    return 0;
}
