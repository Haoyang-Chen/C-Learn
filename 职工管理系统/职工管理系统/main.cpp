//
//  main.cpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#include <iostream>
#include "workerManager.hpp"
#include "Worker.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    WorkerManager wm;
    int choice =0;
    Worker * worker = NULL;
    worker = new Employee(1,"bob",1);
    worker->showInfo();
    //delete worker;
    worker = new Manager(2,"tom",2);
    worker->showInfo();
    //delete worker;
    worker = new Boss(3,"jerry",3);
    worker->showInfo();
    //delete worker;
    while(true){
        wm.Show_Menu();
        cout << "please enter your choice"<<endl;
        cin >> choice ;
        switch (choice) {
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.Add_Emp();
                break;
            case 2:
                wm.Show_Emp();
                break;
            case 3:{
                int ret=wm.IsExist(1);
                if(ret!=-1){
                    cout <<"exise:"<<endl;
                }else{
                    cout <<"not exist"<<endl;
                }
                break;
            }
            case 4:
                wm.Mod_Emp();
                break;
            case 5:
                wm.Find_Emp();
                break;
            case 6:
                wm.sort_emp();
                break;
            case 7:
                wm.Clean_File();
                break;
            default:
                break;
        }
    }
    return 0;
}
