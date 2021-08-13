//
//  myarray.cpp
//  类模版案例
//
//  Created by Haoyang Chen on 2020/12/23.
//
#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
template <class T>
class myarray{
public:
    myarray(int capacity){
        //cout << "myarray的有参构造调用" << endl;
        this->m_capacity=capacity;
        this->m_size=0;
        this->paddress = new T[this->m_capacity];
    }
    myarray(const myarray& arr){
        //cout << "myaray的拷贝构造调用" << endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->paddress = new T[arr.m_capacity];
        for(int i=0;i<this->m_size;i++){
            this->paddress[i]=arr.paddress[i];
        }
    }
    myarray& operator=(const myarray& arr){
        
        if(this->paddress!=NULL){
            delete[] this->paddress;
            this->paddress = NULL;
            this->m_capacity = 0;
            this->m_size =0;
        }
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->paddress = new T[arr.m_capacity];
        for(int i=0;i<arr.m_size;i++){
            this->paddress[i] = arr.paddress[i];
        }
        return *this;
    }
    void push_back(const T & val){
        if(this->m_capacity==this->m_size){
            return;
        }
        this->paddress[this->m_size] = val;
        this->m_size++;
    }
    void pop_back(){
        if(this->m_size==0){
            return;
        }
        this->m_size--;
    }
    T& operator[](int index){
        return this->paddress[index];
    }
    int getapacity(){
        return this->m_capacity;
    }
    int getsize(){
        return this->m_size;
    }
    ~myarray(){
        if (this->paddress != NULL){
            //cout << "myarray的析构函数调用"<<endl;
            delete[] this->paddress;
            this->paddress = NULL;
        }
    }
private:
    T * paddress;
    int m_capacity;
    int m_size;
    
};
