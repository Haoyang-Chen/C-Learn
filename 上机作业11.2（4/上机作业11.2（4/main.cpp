//
//  main.cpp
//  上机作业11.2（4
//
//  Created by Haoyang Chen on 2020/11/2.
//

#include <iostream>
using namespace std;
int check(int m)
{
    int u=m/10;
    u*=10;
    int L=m-u;
    while(m>10)
    {
        m/=10;
    }
    int F=m;
    int J=0;
    if (L==F)
        J=1;
    else
        J=0;
    return J;
}
int main(int argc, const char * argv[])
{
    int a1,a2,a3,a4,a5;
    cin >>a1;
    cin >>a2;
    cin >>a3;
    cin >>a4;
    cin >>a5;
    int result=0;
    result+=check(a1);
    result+=check(a2);
    result+=check(a3);
    result+=check(a4);
    result+=check(a5);
    cout << result <<endl;
    return 0;
}
