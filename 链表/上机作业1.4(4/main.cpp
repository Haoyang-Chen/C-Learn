//
//  main.cpp
//  上机作业1.4(2
//
//  Created by Haoyang Chen on 2021/1/4.
//

#include <iostream>
#include <cassert>

using namespace std;
template<typename T>
class Stack;
template<typename T>
class node{
    T info;
    node<T>*link;
public:
    node(T data=0,node<T>*next=NULL){
        info = data;
        link = next;
    }
    friend class Stack<T>;
};
template<typename T>
class Stack{
    node <T>* top;
public:
    Stack(){
        top=NULL;
    }
    Stack(Stack<T>&ls){
        node<T>*TempP=ls.top->link,*P1;
        
    }
    ~Stack(){
        MakeEmpty();
    }
    void push(const T &data){
        top = new node<T>(data,top);
    }
    bool IsEmpty(){
        return top==NULL;
    }
    T pop(){
        assert(!IsEmpty());
        node<T>*temp=top;
        T data = temp->info;
        top = top->link;
        delete temp;
        return data;
    }
    void MakeEmpty(){
        node<T>*temp;
        while (top!=NULL) {
            temp = top;
            top = top->link;
            delete temp;
        }
    }
    T getTop(){
        assert(!IsEmpty());
        return top->info;
    }
    
};
int main(int argc, const char * argv[]) {
    Stack<int> istack,istack2;
    int m[10]={1,2,3,4,5,6,7,8,9,10};
    int n[10]={6,6,6,6,6,6,6,6,6,6};
    for(int i=0;i<10;i++){
        istack.push(m[i]);
    }
    for(int i=0;i<10;i++){
        istack2.push(n[i]);
    }
    Stack<int> test;
    //test = istack.combine(istack2);
    test.MakeEmpty();
    test = istack;
    while(!test.IsEmpty()){
        cout << test.pop()<<" ";
    }
    return 0;
}

