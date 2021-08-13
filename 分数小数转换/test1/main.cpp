//
//  main.cpp
//  上机作业11.9（2
//
//  Created by Haoyang Chen on 2020/11/9.
//
#include <iostream>
using namespace std;
float Trans (float num)
{
    int k=0;
    int i=0;
    for (int m=1;(int)(num*m)<num*m;m=m*10)
    {
        i=num*m*10;
        k=m*10;
    }
    int value=1;
    for(int m=i;m>=1;m--)
    {
       if (k%m==0&&i%m==0)
       {
           value = m;
           break;
       }
    }
    return value;
}
int main(int argc, const char * argv[])
{
    float num;
    cin >> num;
    int k=0;
    int i=0;
    for (int m=1;(int)(num*m)<num*m;m=m*10)
    {
        i=num*m*10;
        k=m*10;
    }
    cout << num << "=" << i/Trans(num) << "/" << k/Trans(num) <<endl;;
    return 0;
}
