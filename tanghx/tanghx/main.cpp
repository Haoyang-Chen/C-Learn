
/*
已给出集合“类Set”的定义程序。类的属性详情参见实验教材P27，
本次作业完成功能：利用该Set类求两个集合的交集。
即本次作业为Set类的客户程序，利用Set类完成下列功能。

【要求】
1. 求两个整数集合的交集，交集是指由同属于两个集合的元素所构成的新集合。
   对存放在两个文本文件（d1.txt、d2.txt）中的两个整数集合求它们的交集，
   并将求出的交集写入另一个文本文件 Exp03_学号_03_set.txt中
   按每行4个整数的格式，而原始数据文件d1.txt和d2.txt中的内容保持不变。
2. 假设：原始数据文件d1.txt、d2.txt已存在，其中数据见后文，对程序而言，
   文件中的整数数目不详，但都不超过30个整数，且整数之间以若干空格、或者回车换行间隔。
   选择合适的读入方式及控制循环的方式。
   提示：除了可能需要的吃空回车的操作，不使用getline()函数作为从文件读入数据的函数。
3. 不提交存放数据的txt文件，txt文件应该由程序自动在当前文件夹中生成。
4. 本题功能不复制，且set类定义已给，建议控制在30分钟内完成。

【程序】
1. 在main函数中：打开文本文件d1.txt和d2.txt，读取整数序列并统计元素个数，分别存入创建的Set对象中。
2. 在main函数中：关闭文件d1.txt和d2.txt。
3. 在main函数中：调用set的成员函数Intersect()，求出数据交集及其个数，存入新创建的Set对象中。
4. 在main函数中：将交集对象中的整数依次写入到文本文件 Exp03_学号_03_set.txt中，按每行4个整数的格式写入，然后关闭该文件。

● 程序运行前的准备工作：先用记事本建立两个原始数据文件d1.txt和d2.txt，并输入一些整数，
整数之间以若干空格、或者回车换行间隔。两个数据文件的内容为：
d1.txt：
23   17   56   67   88   33   94   45   13
22   18   25   66   86   99   35
d2.txt：
32   21   33   56   66   85   99   20   11
45   98   22   67   81   91   69   65   76   89
● 程序运行后的核对工作：使用记事本打开所生成的文件 Exp03_学号_03_set.txt，
核对内容是否正确。
若d1.txt、d2.txt内容如上，则Exp03_学号_03_set.txt内容应为：
56   67   33   45
22   66   99

测试过程中也可自行设定其他数据完成测试。
并注意体会/学习范例中Set类定义的实现，参考其中对数组元素控制的方式实现第二题的MyString类。
建议自行复现Set类。
*/

//集合类的定义如下
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
 
const int maxnum=19;
enum ErrCode{noErr,overflow};
 
class set
{
    int elements[maxnum];
    int num;
public:
    set(){num=0;}
    bool Member(int);        //判断元素elem是否为本集合的成员
    ErrCode AddElem(int);    //将新元素elem加入本集合
    void RmvElem(int);       //将元素elem从该集合中删去
    void Copy(set);           //将实参所标识的集合中的所有元素复制到本集合中去
    bool Equal(set);          //判断两集合各自包涵的元素是否完全相同
    void print();             //显示本集合的所有元素
    set Intersect(set);       //求本集合与第一参数所指出的集合的交，并且作为返回值
    set Union(set);           //求本集合与第一参数所指出的集合的并，并且作为返回值
    bool Contain(set);        //判断本集合是否包含实参所标识的集合中所有的元素
    int re(int n)
    {
    return elements[n];
    }                              //将对象数组中的值输出
};

bool set::Member(int elem)
{
    int i;
    for(i=0;i<num;i++)
        if(elements[i]==elem)
            return true;
    return false;
}

ErrCode set::AddElem(int elem)
{
    int i;
    for(i=0;i<num;i++)
        if(elements[i]==elem)
            return noErr; //集合中已有elem，不重复加入
    if(num<maxnum)
    {
        elements[num++]=elem;
        return noErr;
    }
    else return overflow;       //数组已满
}

void set::RmvElem(int elem)
{
    int i;
    for(i=0;i<num;i++)
        if(elements[i]==elem)
        {
            for(;i<num-1;i++)  elements[i]=elements[i+1]; //当删除一个元素后，所有后继元素前移一位
            num--;
        }
}

void set::Copy(set s)
{
    int i;
    for(i=0;i<s.num;i++)
        elements[i]= s.elements[i];
    num= s.num;
}

bool set::Equal(set s)
{
    int i;
    if(num!=s.num) return false;       //元素个数不同
    for(i=0;i<num;i++)
        if(!s.Member(elements[i]))
            return false;       //有不同元素
    return true;
}

void set::print()
{
    cout<<"集合的元素包括："<<endl;
    int i;
    for(i=0;i<num;i++)
        cout<<elements[i]<<"  ";
    cout<<endl;
}

set set::Intersect(set s1)
{
    int i,j;
    set s;
    for(i=0;i<num;i++)
        for(j=0;j<s1.num;j++)
            if(elements[i]==s1.elements[j])
            {
                s.elements[s.num++]=elements[i];
                break;
            }
    return s;
}

set set::Union(set s1)
{
    int i;
    set s;
    s.Copy(s1);
    for(i=0;i<num;i++)
        s.AddElem(elements[i]);  //这里忽略了集合可能溢出
    return s;
}

bool set::Contain(set s)
{
    int i;
    for(i=0;i<s.num;i++)
        if(!Member(s.elements[i]))
            return false;
    return true;
}
 
int main()
{
    int i=0;
    ifstream input1,input2;
    set s1,s2,s3;
    int count1=0,count2=0;
    input1.open("/Users/haoyangchen/Desktop/陈昊阳/coding/C++ learning process /tanghx/d1.txt");
    int ch1[maxnum]={};
    int ch2[maxnum]={};
    ErrCode b;
    while(1)
        {
        input1>>ch1[count1];
        count1++;
        if(input1.eof()!=0) break;
        }
    input2.open("/Users/haoyangchen/Desktop/陈昊阳/coding/C++ learning process /tanghx/d2.txt");
    while(1)
        {
        input2>>ch2[count2];
        count2++;
        if(input2.eof()!=0) break;
        }
    for(i=0;i<count1;i++)
        {
        b=s1.AddElem(ch1[i]);
        }
    for(i=0;i<count2;i++)
        {
        b=s2.AddElem(ch2[i]);
        }
    cout<<"s1:";
    s1.print();
    cout<<"s2:";
    s2.print();
    s3=s1.Intersect(s2);
    s3.print();
    int ch3[maxnum]={0};
    int j;
    for(j=0;s3.re(j)!=0;j++)
    {ch3[j]=s3.re(j);
    }
    ofstream ofile;
    ofile.open("Exp03_D2120122_03_set.txt");
    for(i=0;i<j;i++)
    {
        ofile<<ch3[i]<<" ";
        if((i+1)%4==0) ofile<<endl;
    }
    ofile.close();
    return 0;
}

