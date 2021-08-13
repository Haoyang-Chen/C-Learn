//
//  main.cpp
//  上机作业12.28(1
//
//  Created by Haoyang Chen on 2020/12/28.
//

#include <iostream>
#include <string>
using namespace std;

class Mystring
{
    friend ostream &operator<<(ostream &b,Mystring &a);
    friend istream &operator>>(istream &b,Mystring &a);
public:
 // interface functions here
    Mystring(){                   //无参构造函数，
        m_length=0;
        m_data=NULL;
    }
    Mystring(char* c){                                  //将C字符串作为s的初值，构造对象的时从一个字符串拷贝到本类中的m_data中；
        if(m_data=new char[strlen(c)+1]){
        //m_data=c;
            strcpy(m_data, c);
        }
        m_length=strlen(c);
    }
    Mystring(Mystring &a){
        this->m_length=a.length();
        m_data=new char[strlen(a.m_data)+1];
        strcpy(m_data, a.m_data);
    }
    Mystring (int num,char c){        //生成一个字符串，包含num个c字符，构造本对象，按照c重复num次，即如果输入的是 5，’c’,则m_data是“ccccc”;
        m_data = new char[num+1];
        for(int i=0;i<num;i++){
            m_data[i]=c;
        }
        m_data[num]='\0';
    }
    ~Mystring(){                     //析构函数,  释放m_data中的内容，然后把m_data的值赋值成NULL；
        if(this->m_data){
            delete[] this->m_data;
            //delete [] m_data;
        }
        m_data=NULL;
    }
    void assign(char * c){  //赋以新值， 输入的字符串，改写m_data的值， 注意的是，改写之前要先释放原有的，然后按照c字符串，重新分配内容，完成字符串拷贝；
        if(m_data!=NULL){
            delete [] m_data;
        }
        if(m_data=new char[strlen(c)+1]){
        //m_data = c;
            strcpy(m_data, c);
        }
        this->m_length=strlen(c);
    }
    int compare(Mystring& s){ //比较字符串，小于返回-1，等于0，大于1
        if(this->m_length<s.m_length){
            return -1;
        }else if(this->m_length>s.m_length){
            return 1;
        }else{
            return 0;
        }
    }
    int length(){ // 返回字符数量
        return this->m_length;
    }
    char at(int index){ //取单一字符
        return m_data[index];
    }
    void clear(){ //删除全部字符
        m_length=0;
        if(this->m_data !=NULL){
            delete[] this->m_data;
            m_data = NULL;
            //delete [] m_data;
        }
    }
    void show(){ //打印字符串的内容
        if(this->m_data!=NULL){
            cout << m_data<<endl;
        }
        else{
            cout<<"NULL!!"<<endl;
        }
    }
    Mystring operator+=(Mystring &a){
        if(m_data=new char[strlen(a.m_data)+1]){
        strcat(this->m_data, a.m_data);
        }
        this->m_length+=a.m_length;
        return *this;
    }
    char operator[](int index){
        return this->m_data[index];
    }
    Mystring&operator=(Mystring&c)
    {
        delete[]this->m_data;
        if(c.m_data)
        {
            if(m_data=new char[strlen(c.m_data)+1]);
            strcpy(m_data,c.m_data);
            m_length=c.m_length;
        }
        return *this;
    }
    bool operator<(Mystring &a){
        if(this->m_length<a.m_length)return 1;
        else return 0;
    }
    bool operator==(Mystring &a){
        if(m_length==a.m_length&&*m_data==*a.m_data)return 1;
        else return 0;
    }
private:
    char* m_data;  //记录字符串首地址
    int m_length; //记载字符串长度
};

ostream &operator<<(ostream &b,Mystring &a){
    return b<<a.m_data;
}
 
istream &operator>>(istream &b,Mystring &a){
    cin>>a.m_data;
    return b;
}
int main()
{
 Mystring  str1,str2(5,'c'), str3("China");
 str1.show();
 str2.show();
 str3.show();

 str2.assign("C++ programming");
 str2.show();

 str2.clear();
 str2.show();
 str1.assign("test");
 char c1=str3.at(2);
 cout<<c1<<endl;
    
    cout<<str3.length()<<endl;;
 Mystring str4=str1;
 str4.show();
 Mystring str5(str1);
 //str5+=str1;
 str5.show();
    cout<<str5[2]<<endl;
 Mystring str6;
 str6=str5;
 str6.show();
    cout <<str6;
    cin >>str6;
    cout <<str6;
 return 0;
}


