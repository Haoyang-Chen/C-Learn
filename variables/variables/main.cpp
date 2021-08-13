//
//  main.cpp
//  variables
//
//  Created by Haoyang Chen on 2020/10/7.
//

#include <iostream>
using namespace std;
#include <string>
int main(int argc, const char * argv[]) {
    // insert code here...
#define days 7
    cout <<"一周总共有："<< days << "天" << endl ;
    const int month = 12;
    cout <<"一年总共有："<< month << "个月" << endl ;
    std::cout << "Hello, World!\n";
    char ch = 'z';
    std::cout << ch <<"的ASCCII码为"<< (int)ch << std::endl;
    std::cout << "ch所占的字节数为" << sizeof(ch) << std::endl;
    char str[] = "hello world";
    std::cout << str << std::endl;
    std::string str2 = "hello";
    std::cout << str2 << std::endl;
    return 0;
}
