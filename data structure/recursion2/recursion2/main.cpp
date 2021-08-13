//
//  main.cpp
//  recursion
//
//  Created by Haoyang Chen on 2021/8/6.
//

#include <iostream>
using namespace std;

long recursion(long num){
    if (num==1 or num==0)
        return 1;
    return num+2*recursion(long(num/2));
}


int main(int argc, const char * argv[]) {
    int i=0;
    cin>>i;
    for (int k=0;k<i;k++){
        long t=0;
        cin>>t;
        cout<<recursion(t)<<endl;
    }

    return 0;
}

