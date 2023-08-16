//
//  main.cpp
//  1029
//
//  Created by Haoyang Chen on 2022/5/17.
//

#include <iostream>
#include <limits.h>
using namespace std;

void dijkstra(int n,int m,int *si,int *fi,int *vi){
//    int map[501][501];
//    for(int i=0;i<501;i++)
//        for(int j=0;j<501;j++)
//            map[i][j]=INT_MAX;
//    for(int i=0;i<m;i++)
//        if(map[si[i]][fi[i]]>vi[i] && map[fi[i]][si[i]]>vi[i]){
//            map[si[i]][fi[i]]=vi[i];
//            map[fi[i]][si[i]]=vi[i];
//        }
//    for (int i=1;i<=n;i++)
//        map[i][i]=0;
    bool fixed[n+1];
    for (int i=0;i<=n;i++)
        fixed[i]=false;
    fixed[1]=true;
    int res=0;
    for (int i=0;i<n-1;i++){
        int minn=INT_MAX;
        int idx;
        for (int j=0;j<m;j++){
            if (vi[j]<minn &&
                ((!fixed[si[j]] && fixed[fi[j]]) ||
                 (fixed[si[j]] && !fixed[fi[j]]))){
                minn=vi[j];
                idx=j;
            }
        }
        if (minn==INT_MAX)
            break;
        res+=vi[idx];
        fixed[si[idx]]=true;
        fixed[fi[idx]]=true;
    }
    for(int i=1;i<=n;i++){
        if (fixed[i]==false){
            cout << -1 <<endl;
            return;
        }
    }
    cout << res << endl;
    return;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n,m;
        cin >> n >> m;
        int si[m],fi[m],vi[m];
        for (int i=0;i<m;i++)
            cin >> si[i] >> fi[i] >> vi[i];
        dijkstra(n, m, si, fi, vi);
    }
    return 0;
}
