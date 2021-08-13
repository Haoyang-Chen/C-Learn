//
//  worker.h
//  职工管理系统复习
//
//  Created by Haoyang Chen on 2021/7/6.
//

#ifndef worker_h
#define worker_h
#include <iostream>
using namespace std;
#include <string>

class Worker{
public:
    virtual void showInfo()=0;
    virtual int getDeptName()=0;
    int m_Id;
    string m_Name;
    int m_DeptId;
};

#endif /* worker_h */
