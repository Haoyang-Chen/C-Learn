//
//  main.cpp
//  classical monkey peach quest
//
//  Created by Haoyang Chen on 2020/10/26.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int a = 1 ,b = 1;
    for (b = 1 ;b <= 10;b++)
    {
        a = (a + 1)*2;
    }
    cout << a << endl;
    return 0;
}
