//
//  main.cpp
//  1030
//
//  Created by Haoyang Chen on 2022/5/18.
//

#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

void pair_(int n,int *points){
    int res=0;
    stack<int> black;
    stack<int> white;
    for(int pt=0;pt<2*n;pt++){
        if(points[pt]==0){
            if(black.empty())
                white.push(pt);
            else{
                res+=abs(pt-black.top());
                black.pop();
            }
        }
        else{
            if(white.empty())
                black.push(pt);
            else{
                res+=abs(pt-white.top());
                white.pop();
            }
        }
    }
    cout << res << endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int n;
        cin >> n;
        int points[2*n];
        for (int j=0;j<2*n;j++)
            cin >> points[j];
        pair_(n,points);
    }
    return 0;
}
