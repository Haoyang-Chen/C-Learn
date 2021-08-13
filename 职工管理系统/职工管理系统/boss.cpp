//
//  boss.cpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#include "boss.hpp"
Boss::Boss(int id,string name,int Did){
    this->m_name=name;
    this->m_id=id;
    this->m_deptid=Did;
}
void Boss::showInfo(){
    cout <<"id:"<<this->m_id<<endl;
    cout <<"name:"<<this->m_name<<endl;
    cout <<"Department id:"<<m_deptid<<endl;
    cout <<"duty: "<<"emperor"<<endl;
}
string Boss::getDeptName(){
    return (string)"Boss";
}
