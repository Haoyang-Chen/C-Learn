//
//  main.cpp
//  fibonacci
//
//  Created by Haoyang Chen on 2020/12/24.
//

#include <iostream>
int fib(int n){
    if(n<2)
        return 1;
    return fib(n-1)+fib(n-2);
}
int main(int argc, const char * argv[]) {
    std::cout << fib(8);
    return 0;
}
