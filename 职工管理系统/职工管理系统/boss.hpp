//
//  boss.hpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#ifndef boss_hpp
#define boss_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#include "Worker.hpp"
class Boss:public Worker{
public:
    Boss(int id,string name,int Did);
    virtual void showInfo();
    virtual string getDeptName();
};
#endif /* boss_hpp */
