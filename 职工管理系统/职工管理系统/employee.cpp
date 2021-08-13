//
//  employee.cpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#include "employee.hpp"
Employee::Employee(int id,string name,int Did){
    this->m_name=name;
    this->m_id=id;
    this->m_deptid=Did;
}
void Employee::showInfo(){
    cout <<"id:"<<this->m_id<<endl;
    cout <<"name:"<<this->m_name<<endl;
    cout <<"Department id:"<<m_deptid<<endl;
    cout <<"duty: "<<"do what is told to do"<<endl;
}
string Employee::getDeptName(){
    return (string)"employee";
}
