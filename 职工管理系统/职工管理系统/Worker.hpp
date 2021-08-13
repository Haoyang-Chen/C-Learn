//
//  Worker.hpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#ifndef Worker_hpp
#define Worker_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
#include <string>
class Worker{
public:
    int m_id;
    string m_name;
    int m_deptid;
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;
    virtual ~Worker();
};
#endif /* Worker_hpp */
