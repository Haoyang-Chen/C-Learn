//
//  main.cpp
//  上机作业12.18(1
//
//  Created by Haoyang Chen on 2020/12/18.
//

#include <iostream>
#include <fstream>
using namespace std;
void apart (char *s1,char*s2,char*s3){
    int m=0;
    int n=0;
    for(int i=0;i<31;i++){
        if((*(s1+i)>='A'+0)&&(*(s1+i)<='z'+0)){
            *(s2+m)=*(s1+i);
            m++;
        }else {
            *(s3+n)=*(s1+i);
            n++;
        }
    }
}
int main(int argc, const char * argv[]) {
    ofstream ofile;
    ofile.open("/Users/haoyangchen/Desktop/陈昊阳/coding/C++ learning process /上机作业12.18(1/上机作业12.18(1/NewFile.txt");
    char a[50]="The320 ID 102of 1988that 12 boy is 18";
    char b[50],c[50];
    char *s1=a;
    char *s2=b;
    char *s3=c;
    apart(s1, s2, s3);
    ofile <<s1<<endl<<s2<<endl<<s3<<endl;
    ofile.close();
    return 0;
}
