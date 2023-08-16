//
//  main.cpp
//  1021
//
//  Created by Haoyang Chen on 2022/5/11.
//

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void cut(int *l,int *p,int n,int len){
    int re[10001]={0};
    for (int i=1;i<=len;i++){
        re[i]=0;
        for (int j=1;j<=n;j++){
            if (i>=l[j])
                re[i]=max(re[i],(p[j]+re[i-l[j]]));
            else{}
        }
    }
    cout<<re[len]<<endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int len,n;
        cin >>len;
        cin >>n;
        int l[n+1],p[n+1];
        for (int i=1;i<=n;i++){
            cin >> l[i];
            cin >> p[i];
        }
        cut(l,p,n,len);
    }
    return 0;
}
