//
//  main.cpp
//  for test
//
//  Created by Haoyang Chen on 2020/10/11.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here..
    for (int a = 0; a < 100; a++)
    {
        if (a % 7 == 0 ||a % 10 == 7 || a%70 < 10)
        {
            cout << "knock knock" << endl;
        }
        else
        {
            cout << a << endl;
        }
    }
    return 0;
}
