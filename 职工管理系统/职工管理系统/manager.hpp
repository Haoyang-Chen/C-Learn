//
//  manager.hpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#ifndef manager_hpp
#define manager_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#include "Worker.hpp"
class Manager:public Worker{
public:
    Manager(int id,string name,int Did);
    virtual void showInfo();
    virtual string getDeptName();
};
#endif /* manager_hpp */
