//
//  main.cpp
//  上机作业11.6(1
//
//  Created by Haoyang Chen on 2020/11/5.
//

#include <iostream>
using namespace std;
double g(int m,double x)
{
    float value;
    float sum=0;
    for(int i=1;i<=m;i++)
        sum+=i;
    value = sum*x;
    return(value);
}
double f(int n,double x)
{
    float result=1;
    while (n>=1)
    {
        result +=1/g(2*n+1,x);
        n--;
    }
    return(result);
}
int main(int argc, const char * argv[])
{
    int x;
    cout << "please enter x" <<endl;
    cin >> x;
    int n=12;
    float result = f(n,x);
    cout << "f(" << x << ")" << "=" << result << endl;
    return 0;
}
