/*
顺序查找法测试:
1 3 5 12 34 56 78 32 12 35 56 23 45 32
请输入你所要查找的元素
5
你要查找的元素在数组中第一次出现的下标为:2
a b g j y s j z A E D G U F H
请输入你所要查找的元素
g
你要查找的元素在数组中第一次出现的下标为:2
1.3 2.4 3.24 4.28 10.29 20.1456 3.14 100.26
请输入你所要查找的元素
2.4
你要查找的元素在数组中第一次出现的下标为:1
二分查找法测试:
1 2 3 6 7 9 10
请输入你所要查找的元素
6
你要查找的元素在数组中第一次出现的下标为:3
a b c d e f h z
请输入你所要查找的元素
d
你要查找的元素在数组中第一次出现的下标为:3
1.3 2.4 3.5 5.6 7.8 19.8
请输入你所要查找的元素
2.5
查找不到这个数
*/
/*
习题6.4，
  建立对数组元素进行顺序和对半查找的函数模板，
  若找到元素则返回数组下标，找不到则返回-1。
  
编程要求：
- 完成函数模板的定义。
- 对半查找不限制递归或迭代实现，也可以两种方式都实现
- 在main()中分别使用：char, int, double, C++标准string类
  和 自定义的MyString类，五种数据类型定义数组类型，并完成测试。
- 为提高可复用性，建议用函数模板定义测试函数，提高你的工作效率。
- 注意防止二分法陷入死循环。
*/
#include <iostream>
#include <string>
using namespace std;
const int high=20;
const int low=0;
//函数模板原型，其中low和high为查找范围，下标区间
template <typename T>int SequenceSearch(const T *pA, T x, int low, int high)//顺序检索
{
    int i=0;
    while(*(pA+i)!='\0')
    {
        if(*(pA+i)==x) {return i;}
        i++;
    }
    return -1;
}
template <typename T>int BinarySearch( const T *pA, T x, int low, int high)//二分法检索
//注意形参为指针类型与形参为数组，本质上是相同的
{
    int mid=0;//赋初值****
    int j=0;
    if(high==-1) return -1;    //避免空表出错;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<*(pA+mid))
        {
            high=mid-1;
        }
        else if(x>*(pA+mid))
        {
            low=mid+1;
        }
        else return mid;
    }
    if(*(pA+mid)!=x) mid=-1;
    return mid;
}
template <typename T>void Sesearch( T array[])
{
    int re=0;
    T n;
    int i=0;
    for(;array[i]!='\0';i++);
    cout<<"请输入你所要查找的元素"<<endl;
    cin>>n;
    //if(sizeof(n)!=sizeof(T)) re=-1;
    re=SequenceSearch(array,n,low,i);
    if(re==-1)cout<<"查找不到这个数"<<endl;
    else cout<<"你要查找的元素在数组中第一次出现的下标为:"<<re<<endl;
}
template <typename T>void Bisearch( T array[])
{
    int re;
    int i=0;
    T n;
    char temp;
    for(;array[i]!='\0';i++);
    cout<<"请输入你所要查找的元素"<<endl;
    cin>>temp;
    
    re=BinarySearch(array,n,low,i);
    if(re==-1)cout<<"查找不到这个数"<<endl;
    else cout<<"你要查找的元素在数组中第一次出现的下标为:"<<re<<endl;
}
template <typename T>void Print( T array[])
{
    int i=0;
    while(array[i]!='\0')
    {
        cout<<array[i]<<" ";
        i++;
    }
    cout<<endl;
}
int main()
{
    cout<<"顺序查找法测试:"<<endl;
    int ch1[20]={1,3,5,12,34,56,78,32,12,35,56,23,45,32};
    char ch2[20]={'a','b','g','j','y','s','j','z','A','E','D','G','U','F','H'};
    double ch3[20]={1.3,2.4,3.24,4.28,10.29,20.1456,3.14,100.26};
    string str1="AmashcCASsaasBKDFidihxz";
    /*Print(ch1);
    Sesearch(ch1);
    Print(ch2);
    Sesearch(ch2);
    Print(ch3);
    Sesearch(ch3);*/
    cout<<str1<<endl;
    cout<<"二分查找法测试:"<<endl;
    int ch6[20]={1,2,3,6,7,9,10};
    char ch7[20]={'a','b','c','d','e','f','h','z'};
    double ch8[20]={1.3,2.4,3.5,5.6,7.8,19.8};
    Print(ch6);
    Bisearch(ch6);
    Print(ch7);
    Bisearch(ch7);
    Print(ch8);
    Bisearch(ch8);
    
    return 0;
}


