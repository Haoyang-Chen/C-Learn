//
//  main.cpp
//  number quest 1
//
//  Created by Haoyang Chen on 2020/10/26.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int a = 1;
    for (a = 1;a <= 500;a++)
    {
        if(a%3 == 2 && a%5 ==3 && a%7 == 2)
            cout << a << endl;
    }
    return 0;
}
