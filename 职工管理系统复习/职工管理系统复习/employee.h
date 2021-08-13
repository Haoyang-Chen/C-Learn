//
//  employee.h
//  职工管理系统复习
//
//  Created by Haoyang Chen on 2021/7/6.
//

#ifndef employee_h
#define employee_h
#include <iostream>
using namespace std;
#include "worker.h"

class Employee : public Worker{
public:
    Employee(int id, string name, int dId);
    virtual void showInfo();
    virtual int getDeptName();
};

#endif /* employee_h */
