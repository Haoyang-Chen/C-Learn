//
//  main.cpp
//  上机作业11.6(2
//
//  Created by Haoyang Chen on 2020/11/5.
//

#include <iostream>
using namespace std;
int pnj(int x)
{
    int result=1;
    for (int i=2;i<x;i++)
    {
        if(x%i==0)
            result = 0;
    }
    return(result);
}
int main(int argc, const char * argv[])
{
    for(int x=4;x<=50;x+=2)
    {
        for(int i=2;i<=(x/2)+1;i++)
        {
            if ( pnj(i)==1 && pnj(x-i)==1)
                cout << x << "="<< i << "+" << x-i <<endl;
        }
    }
    return 0;
}
