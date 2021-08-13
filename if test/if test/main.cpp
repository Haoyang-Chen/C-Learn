//
//  main.cpp
//  if test
//
//  Created by Haoyang Chen on 2020/10/8.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    using namespace std;
    cout << "请输入分数" << endl;
    int a ;
    cin >> a;
    if (a>600)
    {
        cout << "一本" << endl ;
        if (a >700)
        {
            cout << "tsu" << endl ;
        }
        else if (a >650)
        {
            cout << "pku" << endl ;
        }
        else
        {
            cout << "pu" << endl ;
        }
    }
    else if (a>500)
    {
        cout << "二本" << endl ;
    }
    else if (a >400)
    {
        cout << "三本" << endl ;
    }
    else
    {
        cout << "滚" << endl ;
    }
    return 0;
}
