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
    
    return 0;
}
