//
//  main.cpp
//  tttttttt
//
//  Created by Haoyang Chen on 2020/11/27.
//

#include <iostream>
using namespace std;
void trans(int num){
    char nstr[10];
    int remainder;
    int counter=0;
    char judge;
    if(num>0)judge='+';
    if(num<0)judge='-';
    while(abs(num)>=16){
        remainder=abs(num%16);
        if(remainder<10){
            nstr[0]=remainder+'0';
        }else if(remainder>=10){
            nstr[0]='A'+remainder-10;
        }
        counter++;
        num/=16;
        for(int i=counter;i>0;i--){
            nstr[i]=nstr[i-1];
        }
    }
    nstr[counter+1]='\0';
    nstr[0]=abs(num)+'0';
    cout <<judge<< nstr;
}
int main(int argc, const char * argv[]) {
    int num=-348;
    trans(num);
    return 0;
}
