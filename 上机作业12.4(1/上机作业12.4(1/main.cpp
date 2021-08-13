//
//  main.cpp
//  上机作业12.4(1
//
//  Created by Haoyang Chen on 2020/12/4.
//

#include <iostream>
using namespace std;
void statistics(int a[26]){
    char str[80];
    cout << "please enter 80 letters"<<endl;
    cin.getline(str, 80);
    for(int i=0;i<80;i++){
        if(str[i]>64&&str[i]<91){
            a[str[i]-65]++;
        }else if(str[i]>96&&str[i]<123){
            a[str[i]-97]++;
        }
    }
    a[7]--;
}
int main(int argc, const char * argv[]) {
    int counter[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    statistics(counter);
    for(int i=0;i<26;i++){
        cout << counter[i];
    }
    return 0;
}
