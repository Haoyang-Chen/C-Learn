//
//  main.cpp
//  100以内质数
//
//  Created by Haoyang Chen on 2020/10/30.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int b=0;
    for(int a = 1;a<=1000;a++)
    {
        int c=0;
        for(int b=2; b<a;b++)
        {
            if (a%b==0)
            {
                c++;
            }
        }
        if(c==0)
        {
            cout << a <<"  ";
            b++;
        }
        if (b%5==0)
            cout << endl;
        
    }
    return 0;
}
