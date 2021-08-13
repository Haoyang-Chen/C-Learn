//
//  main.cpp
//  a
//
//  Created by Haoyang Chen on 2021/3/20.
//

#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a=1;
    int b=3;
    ostringstream oss;
    oss<<a<<"/"<<b<<endl;
    string result = oss.str();
    cout << result <<endl;
    return 0;
}
