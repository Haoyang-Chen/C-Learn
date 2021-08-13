//
//  manager.cpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#include "manager.hpp"
Manager::Manager(int id,string name,int Did){
    this->m_name=name;
    this->m_id=id;
    this->m_deptid=Did;
}
void Manager::showInfo(){
    cout <<"id:"<<this->m_id<<endl;
    cout <<"name:"<<this->m_name<<endl;
    cout <<"Department id:"<<m_deptid<<endl;
    cout <<"duty: "<<"do boss's assignments and assign assignments"<<endl;
}
string Manager::getDeptName(){
    return (string)"Manager";
}
