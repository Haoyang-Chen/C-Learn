//
//  main.cpp
//  just joking
//
//  Created by Haoyang Chen on 2020/10/15.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int degree;
    degree = 0;
    cout << "To what extent is your C艹 lessons covered in english?" << endl ;
    cout << "1.scarcely 2.partially 3.totally" << endl;
    cin >> degree;
    if (degree == 1)
    {
        cout << "lucky you" << endl;
    }
    else if (degree == 2)
    {
        int i = 0;
        do
        {
            cout << "?";
            i++;
        }while (i < 11);
    }
    else if (degree ==3)
    {
        cout << "shit!!!" << endl;
    }
    return 0;
}
