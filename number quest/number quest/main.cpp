//
//  main.cpp
//  number quest
//
//  Created by Haoyang Chen on 2020/10/9.
//

#include <iostream>
#include <ctime>
using namespace std ;
int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    int num =rand() % 100 + 1;
    int val = 0;
    while (1)
    {
        cin >> val;
           if (val > num)
           {
               cout << "偏大" << endl;
           }
           else if ( val < num )
           {
               cout << "偏小" << endl;
           }
           else
           {
               cout << "bingo" << endl;
               break;
           }
    }
    return 0;
}
