//
//  main.cpp
//  1023
//
//  Created by Haoyang Chen on 2022/5/12.
//

#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

void travel(int n,int E,int s, int t, int M,int *cost, int *st,int *ed,int *dis){
    int dp[501][101];
    
    bool visit[501][101];
    
    int map[501][501];
    
    for (int i=0;i<=n;i++){
        for(int j=0;j<=M;j++){
            dp[i][j]=INT_MAX;
        }
    }
    
    for (int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
            map[i][j]=INT_MAX;
    }
    
    for(int i=0;i<=M;i++)
        dp[s][i]=0;
    
    for(int i=1;i<=E;i++){
        if(dis[i]<map[st[i]][ed[i]]){
            map[st[i]][ed[i]]=dis[i];
            map[ed[i]][st[i]]=dis[i];
        }
        if((st[i]==s || ed[i]==s)){
            if (st[i]==s)
                    dp[ed[i]][M-cost[ed[i]]]=map[st[i]][ed[i]];
            else
                    dp[st[i]][M-cost[st[i]]]=map[ed[i]][st[i]];
        }
    }
    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=M;j++)
            visit[i][j]=false;
    
    for(int i=0;i<=M;i++)
        visit[s][i]=true;
    
//    int record[501];
    
    int minn;
    
    int l=0,k=M;
//    for(int i=1;i<=n;i++){
//
//        if(i==s)
//            continue;
//        k=M;
//        minn=INT_MAX;
//        for(int j=0;j<=M;j++){
//            if(!visit[i][j]&&dp[i][j]<minn){
//                minn=dp[i][j];
//                l=i;
//                k=j;
//            }
//        }
//        record[i]=k;
//    }
    
    while (true){
        minn=INT_MAX;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=M;j++){
                if (!visit[i][j] && dp[i][j]<minn){
                    minn=dp[i][j];
                    l=i;
                    k=j;
                }
            }
        }
        
        if(minn==INT_MAX)
            break;

        visit[l][k]=true;
        
        for (int i=1;i<=n;i++){
            if(i==l || i==s)
                continue;
            if (k-cost[i]>=0 && dp[i][k-cost[i]]>dp[l][k]+map[l][i] && map[l][i]!=INT_MAX){
                dp[i][k-cost[i]]=dp[l][k]+map[l][i];
//                if(dp[i][k-cost[i]]<dp[i][record[i]])
//                    record[i]=k-cost[i];
            }
        }
    }
    
    int ans=INT_MAX;
    for (int j=0;j<=M;j++){
        if (dp[t][j]<ans)
            ans=dp[t][j];
    }
    if (ans==INT_MAX){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n,E,s,t,M;
        cin >> n >> E >> s >> t >> M;
        int cost[501];
        for (int i=1;i<=n;i++)
            cin >> cost[i];
        int st[500001],ed[500001],dis[500001];
        for (int i=1;i<=E;i++)
            cin >> st[i] >> ed[i] >> dis[i];
        travel(n,E,s,t,M,cost,st,ed,dis);
    }
    return 0;
}

/*
1
4 3 1 4 10
2 2 2 2
1 3 1
3 2 1
2 4 1
1 2 3
3 4 3
*/
