//
//  main.cpp
//  1020
//
//  Created by Haoyang Chen on 2022/5/11.
//

#include <iostream>
#include <limits.h>
using namespace std;

void mat_mal(int * row,int *col,int n){
    int cost[n][n];
    for (int i=0;i<n;i++)
        cost[i][i]=0;
    for(int len=2;len<=n;len++){
        for (int i=0;i<n-len+1;i++){
            int j=i+len-1;
            cost[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int c=cost[i][k]+cost[k+1][j]+row[i]*col[k]*col[j];
                if (c<cost[i][j])
                    cost[i][j]=c;
            }
        }
    }
    cout<<cost[0][n-1]<<endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n;
        cin >> n;
        int row[n];
        int col[n];
        for (int i=0;i<n;i++){
            cin >> row[i];
            cin >> col[i];
        }
        mat_mal(row, col, n);
    }
    return 0;
}
