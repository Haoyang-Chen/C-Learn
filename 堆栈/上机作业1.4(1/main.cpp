//
//  main.cpp
//  上机作业1.4(1
//
//  Created by Haoyang Chen on 2021/1/4.
//

#include <iostream>
#include <cassert>
using namespace std;
template<typename T>
class Stack{
    int top;
    T*elements;
    int maxsize;
public:
    Stack(int maxs){
        maxsize = maxs;
        top = -1;
        elements = new T[maxsize];
        assert(elements!=0);
    }
    bool IsEmpty()const{
        return top==-1;
    }
    bool IsFull()const{
        return top==maxsize-1;
    }
    T get_elem(int i){
        assert(i<=top&&i>=0);
        return elements[i];
    }
    T pop(){
//        assert(! IsEmpty());
        return elements[top--];
    }
    void Push(const T &data){
        assert(!IsFull());
        elements[++top]=data;
    }
    void makeEmpty(){
        top=-1;
    }
    void printStack(){
        for(int i=0;i<=top;i++){
            cout << elements[i] <<'\t';
        }
        cout << endl;
    }
    ~Stack(){
        delete [] elements;
    }
};
int main(int argc, const char * argv[]) {
    int i,a[10]={0,1,2,3,4,5,6,7,8,9},b[10];
    Stack<int>istack(10);
    for(i=0;i<10;i++){
        istack.Push(a[i]);
    }
    if(istack.IsFull()){
        cout << "栈满" <<endl;
    }
    istack.printStack();
    for(i=0;i<10;i++){
        b[i]=istack.pop();
    }
    if(istack.IsEmpty()){
        cout << "栈空" <<endl;
    }
    for(i=0;i<10;i++){
        cout << b[i]<<'\t';
    }
    cout <<endl;
    istack.pop();
    return 0;
}
