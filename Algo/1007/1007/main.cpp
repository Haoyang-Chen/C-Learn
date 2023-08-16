//
//  main.cpp
//  1007
//
//  Created by Haoyang Chen on 2022/4/25.
//

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

void Max_Mal(int num_N,int num_M,string nums){
    int dp[num_N+1][num_M+1];
    int num[num_N+1][num_N+1];
    for (int i=0;i<num_N;i++){
        int sum=0;
        for (int j=i;j<num_N;j++){
            sum=sum*10+nums[j]-'0';
            num[i][j]=sum;
        }
    }
    memset(dp, -1, sizeof(dp));
    for (int i=0;i<num_N;i++){
        dp[i][0]=num[0][i];
    }
    for (int i=0;i<num_N;i++){
        for (int j=1;j<=num_M;j++){
            for (int k=0;k<i;k++){
                dp[i][j]=max(dp[i][j], dp[k][j-1]*num[k+1][i]);
            }
        }
    }
    cout << dp[num_N-1][num_M]<<endl;
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    for (int i=0;i<num;i++){
        int num_N,num_M;
        cin >> num_N;
        cin >> num_M;
        string nums;
        cin >> nums;
        Max_Mal(num_N,num_M,nums);
    }
    return 0;
}
