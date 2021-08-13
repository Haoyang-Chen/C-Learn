//
//  main.cpp
//  上机作业11.2（2
//
//  Created by Haoyang Chen on 2020/11/2.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[])
{
    ofstream ofile;
    ofile.open("/Users/haoyangchen/Desktop/陈昊阳/C++ learning process /hellow-world/上机作业11.2（2/100以内质数.txt");
    int b=0;
    for(int a = 1;a<=100;a++)
    {
        int c=0;
        for(int b=2; b<a;b++)
        {
            if (a%b==0)
            {
                c++;
            }
        }
        if(c==0)
        {
            cout << a <<"  ";
            ofile << a << "  ";
            b++;
        }
        if (b%5==0)
        {
            cout << endl;
            ofile << '\n';
        }
    }
    ofile.close();
    return 0;
}
