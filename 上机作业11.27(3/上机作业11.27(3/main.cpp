//
//  main.cpp
//  上机作业11.27(3
//
//  Created by Haoyang Chen on 2020/11/26.
//

#include <iostream>
#include <string>
using namespace std;
void transit(int num){
    char nstr[10];
    int remainder;
    int i=0;
    int counter=0;
    while(abs(num)>=16){
        num=num/16;
        counter++;
    }
    nstr[counter+1]='\0';
    for(int i=1;i<=counter;i++){
        remainder=num%16;
        if(abs(remainder)>=10){
            switch (abs(remainder)) {
                case 10:
                    nstr[0]='A';
                    break;
                case 11:
                    nstr[0]='B';
                    break;
                case 12:
                    nstr[0]='C';
                    break;
                case 13:
                    nstr[0]='D';
                    break;
                case 14:
                    nstr[0]='E';
                    break;
                case 15:
                    nstr[0]='F';
                    break;
                default:
                    break;
            }
        }else{
            nstr[0]=abs(remainder)+'0';
        }
        for(int m=i;m>0;m--){
            nstr[m]=nstr[m-1];
        }
        num=num%16;
    }
    nstr[0]=num+'0';
    for(int i=9;i>=0;i--){
        cout << nstr[i];
    }
    cout << nstr;
}
int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    transit(-348);
    return 0;
}
