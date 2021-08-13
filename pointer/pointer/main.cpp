//
//  main.cpp
//  pointer
//
//  Created by Haoyang Chen on 2020/11/25.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    float f = 1.0;
    short c = *(short*)&f;
    int a[5]={1,2,3,4,5};
    int * test = new int[5];
    test[0] = 1;
    test[1] = 2;
    std::cout << test[1];
    delete[] test;
    return 0;
}
