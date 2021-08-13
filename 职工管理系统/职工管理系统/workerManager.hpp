//
//  workerManager.hpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#ifndef workerManager_hpp
#define workerManager_hpp

#include <stdio.h>
#include <iostream>
#include "Worker.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"
#include <fstream>
#define FILENAME "/Users/haoyangchen/Desktop/陈昊阳/coding/C++ learning/职工管理系统/职工管理系统/empFile.txt"

using namespace std;
class WorkerManager{
public:
    WorkerManager();
    void Show_Menu();
    void exitSystem();
    int m_EmpNum;
    Worker ** m_EmpArray;
    void Add_Emp();
    void save();
    bool m_FileIsEmpty;
    int get_EmpNum();
    void init_Emp();
    void Show_Emp();
    int IsExist(int id);
    void Del_Emp();
    void Mod_Emp();
    void Find_Emp();
    void sort_emp();
    void Clean_File();
    ~WorkerManager();
};
#endif /* workerManager_hpp */
