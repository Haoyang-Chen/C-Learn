//
//  main.cpp
//  职工管理系统复习
//
//  Created by Haoyang Chen on 2021/7/6.
//

#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"

int main(int argc, const char * argv[]) {
    Worker *worker=NULL;
    worker=new Employee(1,"dsad",1);
    worker->showInfo();
    
    
    WorkerManager wm;
    
    int choice=0;
    while (true){
        wm.Show_Menu();
        cout<<"enter your choice"<<endl;
        cin>>choice;
        switch (choice){
            case 0:
                wm.ExitSystem();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                break;
        }
    }
    return 0;
}
