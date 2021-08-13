//
//  employee.hpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#ifndef employee_hpp
#define employee_hpp

#include <stdio.h>
#include <iostream>
#include "Worker.hpp"
using namespace std;
class Employee:public Worker{
public:
    virtual void showInfo();
    virtual string getDeptName();
    Employee(int id,string name,int Did);
};
#endif /* employee_hpp */
