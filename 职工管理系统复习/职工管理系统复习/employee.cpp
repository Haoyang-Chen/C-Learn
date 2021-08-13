//
//  employee.cpp
//  职工管理系统复习
//
//  Created by Haoyang Chen on 2021/7/6.
//

#include <stdio.h>
#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee(int id, string name, int dId){
    this->m_Id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}
void Employee::showInfo(){
    cout<<"id: "<<this->m_Id
    <<"\tname: "<<this->m_Name
    <<"\tdepartment: "<<this->m_DeptId
    <<"\trole: employee"<<endl;
}
int Employee::getDeptName(){
    return this->m_DeptId;
}

