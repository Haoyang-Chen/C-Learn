//
//  main.cpp
//  上机作业11.2（1
//
//  Created by Haoyang Chen on 2020/11/2.
//

#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[])
{
    float x=1,a=1;
    while(1)
    {
        a=(x*x-10*(x*sin(x)+cos(x)))/(2*x-10*sin(x));
        if (fabs(x-a)<1e-5)
        {
            cout << x <<endl;
            break;
        }
        x=a;
    }
    return 0;
}
