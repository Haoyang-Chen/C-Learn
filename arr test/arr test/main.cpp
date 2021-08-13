//
//  main.cpp
//  arr test
//
//  Created by Haoyang Chen on 2020/10/18.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[5] = {1,2,3,4,5};
    for (int i = 0;i < 5 ;i++ )
    {
        cout << arr[i] << endl;
    }
    cout << "the first element's location is " << &arr[1] << endl;
    cout << "the size of arr is " << sizeof(arr) << endl;
    cout << "the size of arr[1] is " << sizeof(arr[1]) << endl;
    return 0;
}
