//
//  main.cpp
//  上机作业11.9(1
//
//  Created by Haoyang Chen on 2020/11/9.
//

int Acm (int m,int n)
{
    if (m==0)
        return n+1;
    else if (n==0)
        return Acm(m-1, 1);
    else if (n>0&&m>0)
        return Acm(m-1, Acm(m, n-1));
    return 0;
}
#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int m,n;
    cin >>m;
    cin >>n;
    int y=Acm(m,n);
    cout << y <<endl;
    return 0;
}
