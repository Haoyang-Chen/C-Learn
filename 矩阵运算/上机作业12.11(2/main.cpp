//
//  main.cpp
//  上机作业12.11(2
//
//  Created by Haoyang Chen on 2020/12/11.
//

#include <iostream>
using namespace std;
class point {
public:
    int value,row,col;
};
int main(int argc, const char * argv[]) {
    point p[4]={0,0,0,0};
    int matrix[4][5]={11,12,13,14,15,2,5,9,8,7,16,14,11,12,13,8,2,10,9,7};
    for(int i=0;i<4;i++){
        p[i].value=matrix[i][0];
        p[i].col=0;
        p[i].row=i;
        for(int m=0;m<4;m++){
            if(matrix[i][m+1]>=matrix[i][m]){
                p[i].col=m+1;
                p[i].value=matrix[i][m+1];
            }
        }
    }
    for(int m=0;m<4;m++){
        int counter=0;
        for(int i=0;i<4;i++){
            if(p[m].value>matrix[i][p[m].col]){
                counter++;
            }
        }
        if (counter==0){
            cout << p[m].value<<endl;
        }
    }
    return 0;
}
