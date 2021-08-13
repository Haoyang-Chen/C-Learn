//
//  main.cpp
//  factorial
//
//  Created by Haoyang Chen on 2021/8/6.
//

#include <iostream>
using namespace std;

long factorial(long num){
    if (num==1)
        return 1;
    return num*factorial(num-1);
}


int main(int argc, const char * argv[]) {
    int i=0;
    cin>>i;
    for (int k=0;k<i;k++){
        long t=0;
        cin>>t;
        cout<<factorial(t)<<endl;
    }

    return 0;
}
