//
//  main.cpp
//  1008
//
//  Created by Haoyang Chen on 2022/4/25.
//

#include <iostream>
#include <math.h>
using namespace std;



void C_Attack(int n,int *num){
    int d[n],u[n];
    for (int i=0;i<n;i++){
        d[i]=u[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[i]<=num[j])
                d[i]=max(d[i], d[j]+1);
            else
                u[i]=max(u[i], u[j]+1);
        }
    }
    int maxd=0,maxu=0;
    for(int i=0;i<n;i++){
        maxd=max(maxd,d[i]);
        maxu=max(maxu,u[i]);
      }
    cout<<maxd<<' '<<maxu<<endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin>>iter;
    for (int i=0;i<iter;i++){
        int n;
        cin>>n;
        int num[n];
        for (int i=0;i<n;i++){
            cin >> num[i];
        }
        C_Attack(n, num);
    }
    return 0;
}
