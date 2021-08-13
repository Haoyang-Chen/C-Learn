//
//  main.cpp
//  类模版案例
//
//  Created by Haoyang Chen on 2020/12/23.
//

#include <iostream>
#include "myarray.cpp"
#include <string>

using namespace std;
void printarray(myarray <int>& arr){
    for(int i=0;i<arr.getsize();i++){
        cout << arr[i]<<endl;
    }
}
void test01(){
    myarray<int>arr1(5);
    for(int i=0;i<5;i++){
        arr1.push_back(i);
    }
    cout << "arr1:"<<endl;
    printarray(arr1);
    cout <<"arr1:capacity:"<<arr1.getapacity()<<endl;
    cout <<"arr1:size"<<arr1.getsize()<<endl;
    myarray<int>arr2(arr1);
    arr2.pop_back();
    cout<<"arr2:"<<endl;
    printarray(arr2);
    cout <<"arr2:capacity:"<<arr2.getapacity()<<endl;
    cout <<"arr2:size"<<arr2.getsize()<<endl;
    //myarray<int>arr3(100);
    //arr3 = arr1;
}
class person{
public:
    person(){};
    person(string name,int age){
        this->m_age=age;
        this->m_name=name;
    }
    string m_name;
    int m_age;
};
void print_personarray(myarray<person>& arr){
    for(int i=0;i<arr.getsize();i++){
        cout <<"name:"<<arr[i].m_name<<endl;
        cout <<"age:"<<arr[i].m_age<<endl;
    }
}
void test02(){
    myarray<person>arr(10);
    person p1("a",999);
    person p2("b",20);
    person p3("c",2);
    person p4("d",30);
    person p5("e",10);
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);
    print_personarray(arr);
    cout <<"arr capacity:"<<arr.getapacity()<<endl;
    cout <<"arr size:"<<arr.getsize()<<endl;
}
int main(int argc, const char * argv[]) {
    test01();
    test02();
    return 0;
}
