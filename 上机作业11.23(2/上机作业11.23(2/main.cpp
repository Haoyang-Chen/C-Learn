//
//  main.cpp
//  上机作业11.23(2
//
//  Created by Haoyang Chen on 2020/11/23.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//void target(int a[]){
//    int b[]{0};
//    int k=0;
//    for(int i=1;i<9;i++){
//        if((a[i-1]>a[i]&&a[i+1]>a[i])||(a[i-1]<a[i]&&a[i+1]<a[i])){
//            b[k]=a[i];
//            k++;
//        }
//    }
//    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++){
//        cout <<b[i]<<endl;
//    }
//}
int main(int argc, const char * argv[]) {
    int a[10];
    for (int i=0;i<10;i++){
        cin >> a[i];
    }
//    for (int i=0;i<10;i++){
//        cout << a[i];
//    }cout <<endl;
//    target(a);
//    target(t);
    ifstream ifile;
    ofstream ofile;
    ifile.open("/Users/haoyangchen/Desktop/陈昊阳/C++ learning process /上机作业11.23(2/NewFile.txt");
    int c[10];
    for(int i=0;i<10;i++){
        ifile >> c[i];
        if (ifile.ios_base::eof() !=0)break;
    }
    int b[]{0};
    int k=0;
    int counter=0;
    for(int i=1;i<9;i++){
        if((a[i-1]>a[i]&&a[i+1]>a[i])||(a[i-1]<a[i]&&a[i+1]<a[i])){
            b[k]=a[i];
            k++;
            counter++;
        }
    }
    cout <<"峰值数为："<<endl;
    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++){
        cout <<b[i]<<" "<<endl;
    }
    cout <<"有"<<counter <<"个"<<endl;
    int p[]{0};
    k=0;
    counter=0;
    for(int i=1;i<9;i++){
        if((a[i-1]>a[i]&&a[i+1]>a[i])||(a[i-1]<a[i]&&a[i+1]<a[i])){
            p[k]=a[i];
            k++;
            counter++;
        }
    }
    cout <<"峰值数为："<<endl;
    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++){
        cout <<p[i]<<" "<<endl;
    }
    cout <<"有"<<counter <<"个"<<endl;
    ofile.open("/Users/haoyangchen/Desktop/陈昊阳/C++ learning process /上机作业11.23(2/NewFile-1.txt");
    int i=0;
    while(1){
        ofile << c[i];
        if (c[i]=='\0')break;
    }
    ofile.close();
    ifile.close();
    return 0;
}
