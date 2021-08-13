//
//  main.cpp
//  array transposition task
//
//  Created by Haoyang Chen on 2020/10/27.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0;i<5;i++)
    {
        cout << arr[i] ;
    }
    cout << endl;
    int start = 0;
    int end = sizeof(arr)/sizeof(arr[0])-1;
    while (start < end)
    {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] =temp;
    start++;
    end--;
    }
    for(int i = 0;i<5;i++)
    {
        cout << arr[i] ;
    }
    return 0;
}
