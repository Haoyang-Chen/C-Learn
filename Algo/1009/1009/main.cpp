//
//  main.cpp
//  1009
//
//  Created by Haoyang Chen on 2022/4/25.
//

#include <iostream>
using namespace std;

void C_Attack(int n,int *num){
    int less[n];
    fill(less, less+n, 1);
    int M=0;
    less[n-1]=1;
    for (int i=n-1;i>=0;i--){
        int max=1;
        for (int j=i;j<n;j++){
            if (num[j]<=num[i]&&j!=i){
                if (max<less[j]+1){
                    max=less[j]+1;
                }
            }
        }
        less[i]=max;
        if (max>M)
            M=max;
    }
    cout<<M<<endl;
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
