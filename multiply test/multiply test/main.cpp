//
//  main.cpp
//  multiply test
//
//  Created by Haoyang Chen on 2020/10/11.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    //乘法口诀表
    for(int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << "x" << i << "=" << j*i << " ";
        }
        cout << endl;
    }
    return 0;
}
