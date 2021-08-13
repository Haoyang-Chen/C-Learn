//
//  main.cpp
//  上机作业12.21(1
//
//  Created by Haoyang Chen on 2020/12/21.
//

#include <iostream>
using namespace std;
template<class T,typename num>
void sort1(T a[],num n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j+1].grade>a[j].grade){
                T temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i].grade<<" "<<endl;
    }
}
template<class T,typename num>
void sort2(T a[],num n){
    int j;
    for(int i=0;i<n;i++){
        T temp = a[i];
        j=i;
        while(j>0&&temp.grade>a[j-1].grade){
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
    }
    for(int i=0;i<n;i++){
        cout << a[i].grade<<" "<<endl;
    }
}
template<class T,typename num>
void sort3(T a[],num n){
    int i,j,k;
    T temp;
    for(i=0;i<n;i++){
        k=i;
        temp=a[i];
        for(j=i;j<n;j++){
            if(a[j].grade>temp.grade){
                k=j;
                temp=a[j];
            }
            if(k!=i){
                temp=a[i];
                a[i]=a[k];
                a[k]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i].grade<<" "<<endl;
    }
}
class student{
public:
    int grade;
    student(int a){
        grade=a;
    }
    student(){
        grade=60;
    }
};
int main(int argc, const char * argv[]) {
    student s1(62),s2(61),s3(65),s4(64);
    student stu[4]={s1,s2,s3,s4};
    sort1(stu,4);
    sort2(stu,4);
    sort3(stu,4);
    return 0;
}
