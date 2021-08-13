//
//  workerManager.cpp
//  职工管理系统复习
//
//  Created by Haoyang Chen on 2021/7/6.
//
#include <iostream>
#include "workerManager.h"
using namespace std;

WorkerManager::WorkerManager(){
    
}

void WorkerManager::Show_Menu(){
    cout<<"****0.exit****"<<endl;
    cout<<"****1.add*****"<<endl;
    cout<<"****2.show****"<<endl;
    cout<<"****3.delete**"<<endl;
    cout<<"****4.edit****"<<endl;
    cout<<"****5.find****"<<endl;
    cout<<"****6.sort****"<<endl;
    cout<<"****7.clear***"<<endl;
    cout<<endl;
}

void WorkerManager::ExitSystem(){
    cout<<"bye"<<endl;
    exit(0);
}
WorkerManager::~WorkerManager(){
    
}
