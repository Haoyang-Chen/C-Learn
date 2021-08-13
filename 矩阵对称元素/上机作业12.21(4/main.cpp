//
//  main.cpp
//  上机作业12.21(4
//
//  Created by Haoyang Chen on 2020/12/21.
//

#include <iostream>
using namespace std;
const int N = 4;
template <typename T>
int JudgeSym(T a[][N]){
    int counter=0;
    for(int i=1;i<4;i++){
        for(int j=0;j<=i;j++){
            if(a[i][j]!=a[j][i]){
                counter++;
            }
        }
    }
    if(counter!=0){
        return 0;
    }else{
        return 1;
    }
}
int main(int argc, const char * argv[]) {
    int mat1[4][4]={1, 2, 3, 4, 2, 1, 4, 3, 3, 4, 1, 2, 4, 3, 2, 1};
    char mat2[4][4]={'a','b','c','d','b','a','b','c','c','b','a','b','d','c','b','a'};
    cout << JudgeSym(mat1)<<endl;
    cout << JudgeSym(mat2)<<endl;
    return 0;
}
