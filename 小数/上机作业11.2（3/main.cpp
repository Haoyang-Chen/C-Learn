//
//  main.cpp
//  上机作业11.2（3
//
//  Created by Haoyang Chen on 2020/11/2.
//

#include <iostream>
using namespace std;
int digit(int num,int k)
{
    int i=0;
    int u=0;
    for(;k>1;k--)
    {
    num=num/10;
        i=num;
        u=num;
    }
    u/=10;
    i=i-u*10;
    return i;
}
int main(int argc, const char * argv[])
{
    int a;
    cin >> a;
    int b ;
    cin >> b;
    int m;
    m=digit(a,b);
    cout << m <<endl;
    return 0;
}
