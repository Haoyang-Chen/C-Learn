//
//  main.cpp
//  1022
//
//  Created by Haoyang Chen on 2022/5/11.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void LCS(string a,string b){
    int lena=a.length();
    int lenb=b.length();
    int m[501][501]={0};
    for (int i=1;i<=lena;i++){
        for (int j=1;j<=lenb;j++){
            if(a[i-1]==b[j-1]){
                m[i][j]=m[i-1][j-1]+1;
            }else {
                m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
    }
    cout<<m[lena][lenb]<<endl;
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >>iter;
    for(int i=0;i<iter;i++){
        string s1,s2;
        cin >>s1;
        cin >>s2;
        LCS(s1, s2);
    }
    return 0;
}
