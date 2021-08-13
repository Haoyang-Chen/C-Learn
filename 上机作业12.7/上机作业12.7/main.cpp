//
//  main.cpp
//  上机作业12.7
//
//  Created by Haoyang Chen on 2020/12/7.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int matrix[5][5];
    for(int i=0;i<5;i++){
        for(int m=0;m<5;m++){
            printf("please enter the %d element of the %d row \n",m,i);
            cin >> matrix[i][m];
        }
    }
    for(int i=0;i<5;i++){
        for(int m=0;m<5;m++){
            cout << matrix[i][m] <<" ";
        }
        cout << endl;
    }
    int matrixT[5][5];
    for (int i=0;i<5;i++){
        for(int m=0;m<5;m++){
            matrixT[m][i]=matrix[i][m];
        }
    }
    cout << "after transpose:"<<endl;
    for(int i=0;i<5;i++){
        for(int m=0;m<5;m++){
            cout << matrixT[i][m] <<" ";
        }
        cout << endl;
    }
    return 0;
}
