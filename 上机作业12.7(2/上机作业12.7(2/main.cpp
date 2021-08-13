//
//  main.cpp
//  上机作业12.7(2
//
//  Created by Haoyang Chen on 2020/12/7.
//

#include <iostream>
using namespace std;
struct person{
    char name[20];
    int count;
};
int main(int argc, const char * argv[]) {
    person leader[8];
    for(int i=0;i<8;i++){
        printf("enter the name of the %d candidate \n",i+1);
        cin >> leader[i].name;
        printf("enter the count \n");
        cin >> leader[i].count;
    }
    for(int i=0;i<8;i++){
        for(int m=0;m<7-i;m++){
            if (leader[m].count>leader[m+1].count){
                person temp=leader[m+1];
                leader[m+1]=leader[m];
                leader[m]=temp;
            }
        }
    }
    cout <<"the candidates are sorted as:";
    for(int i=0;i<8;i++){
        cout << leader[i].name<<" ";
    }
    return 0;
}
