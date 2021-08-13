//
//  main.cpp
//  recursion3
//
//  Created by Haoyang Chen on 2021/8/6.
//

#include <iostream>
#include <math.h>
using namespace std;

long recursion(int num){
    if (num==1 or num==0)
        return 1;
    return num*num+3*recursion(ceil(num/3.0));
}


int main(int argc, const char * argv[]) {
    int i=0;
    cin>>i;
    for (int k=0;k<i;k++){
        int t=0;
        cin>>t;
        cout<<recursion(t)<<endl;
    }

    return 0;
}


