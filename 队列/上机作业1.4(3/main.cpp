//
//  main.cpp
//  上机作业1.4(3
//
//  Created by Haoyang Chen on 2021/1/4.
//

#include <iostream>
#include <cassert>
using namespace std;
template<typename T>class Queue;
template<typename T>
class Node{
    T info;
    Node*link;
public:
    Node(T data=0,Node*l=NULL);
    friend class Queue<T>;
};
template<typename T>
Node<T>::Node(T data,Node*l){
    info=data;
    link=l;
}
template<typename T>
class Queue{
    Node<T>*front,*rear;
public:
    Queue(){
        rear=front=NULL;
    }
    ~Queue();
    bool IsEmpty(){
        return front == NULL;
    }
    void EnQue(const T &data);
    T DeQue();
    T GetFront();
    void MakeEmpty();
};
template<typename T>
void Queue<T>::MakeEmpty(){
    Node<T>*temp;
    while(front!=NULL){
        temp=front;
        front=front->link;
        delete temp;
    }
}
template<typename T>
Queue<T>::~Queue(){
    MakeEmpty();
}
template<typename T>
void Queue<T>::EnQue(const T &data){
    if(front==NULL){
        front=rear=new Node <T>(data,NULL);
    }else{
        rear=rear->link=new Node<T>(data,NULL);
    }
}
template<typename T>
T Queue<T>::DeQue(){
    assert(!IsEmpty());
    Node<T>*temp=front;
    T data =temp->info;
    front = front->link;
    delete temp;
    return data;
}
template<typename T>
T Queue<T>::GetFront(){
    assert(!IsEmpty());
    return front->info;
}

int main(int argc, const char * argv[]) {
    int i;
    Queue<char>que;
    char str1[]="abcdefghijklmnop";
    for(i=0;i<17;i++){
        que.EnQue(str1[i]);
    }
    for(i=0;i<17;i++){
        cout <<que.DeQue();
    }
    cout << endl;
    if(que.IsEmpty()){
        cout << "队空"<<endl;
    }
    return 0;
}
