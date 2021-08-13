//
//  workerManager.cpp
//  职工管理系统
//
//  Created by Haoyang Chen on 2020/12/30.
//

#include "workerManager.hpp"

using namespace std;
WorkerManager::WorkerManager(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout << "File does not exist"<<endl;
        this->m_EmpNum =0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "file empty"<<endl;
        this->m_EmpNum =0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    int num=this->get_EmpNum();
    cout << "the number of worker is: "<<num<<endl;
    this->m_EmpNum=num;
    
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    this->init_Emp();
//    for(int i=0;i<this->m_EmpNum;i++){
//        cout <<"id: "<<this->m_EmpArray[i]->m_id
//        <<"name: "<<this->m_EmpArray[i]->m_name
//        <<"department id: "<<this->m_EmpArray[i]->m_deptid<<endl;
//    }
}
bool m_FileIsEmpty;
void WorkerManager::Show_Menu(){
    cout << "welcome"<<endl;
    cout << "0.exit"<<endl;
    cout << "1.add"<<endl;
    cout << "2.show"<<endl;
    cout << "3.delete"<<endl;
    cout << "4.modify"<<endl;
    cout << "5.find"<<endl;
    cout << "6.sort"<<endl;
    cout << "7.clear"<<endl;
}
void WorkerManager::exitSystem(){
    cout <<"bye"<<endl;
    exit(0);
}
void WorkerManager::Add_Emp(){
    cout <<"please enter how many people you would like to add"<<endl;
    int add_num=0;
    cin>>add_num;
    if(add_num>0){
        int newsize = this->m_EmpNum+add_num;
        Worker** newspace =  new Worker*[newsize];
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<m_EmpNum;i++){
                newspace[i]=this->m_EmpArray[i];
            }
        }
        for(int i=0;i<add_num;i++){
            int id;
            string name;
            int dselect;
            cout <<"the "<<i+1<<"th id is"<<endl;
            cin>>id;
            cout <<"the "<<i+1<<"th name is"<<endl;
            cin>>name;
            cout <<"the "<<i+1<<"th department is"<<endl;
            cout <<"1.employee 2.manager 3.boss"<<endl;
            cin>>dselect;
            Worker * worker = NULL;
            switch (dselect) {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }
            newspace[this->m_EmpNum+i] = worker;
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray = newspace;
        this->m_EmpNum = newsize;
        this->m_FileIsEmpty=false;
        cout <<"successfully added "<<add_num<<" people"<<endl;
        this->save();
    }else{
        cout <<"wrong"<<endl;
    }
}
void WorkerManager::save(){
    ofstream ofs;
    ofs.open("/Users/haoyangchen/Desktop/陈昊阳/coding/C++ learning/职工管理系统/职工管理系统/empFile.txt",ios::app);
    for(int i=0;i<this->m_EmpNum;i++){
        ofs << this->m_EmpArray[i]->m_id<<" "
            << this->m_EmpArray[i]->m_name<<" "
            << this->m_EmpArray[i]->m_deptid<<endl;
    }
    ofs.close();
}
int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int did;
    int num=0;
    while (ifs >> id&&ifs>>name&&ifs>>did){
        num++;
    }
    return num;
}
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int did;
    int index=0;
    while(ifs>>id&&ifs>>name&&ifs>>did){
        Worker * worker = NULL;
        if(did==1){
            worker= new Employee(id,name,did);
        }else if(did==2){
            worker = new Manager(id,name,did);
        }else if(did==3){
            worker = new Boss(id,name,did);
        }
        this->m_EmpArray[index]=worker;
        index++;
    }
}
void WorkerManager::Show_Emp(){
    if(this->m_FileIsEmpty){
        cout << "file does not exist or have no record"<<endl;
    }else{
        for(int i=0;i<m_EmpNum;i++){
            this->m_EmpArray[i]->showInfo();
        }
    }
}
int WorkerManager::IsExist(int id){
    int index=-1;
    for(int i=0;i<this->m_EmpNum;i++){
        if(this->m_EmpArray[i]->m_id==id){
            index =i;
            break;
        }
    }
    return index;
}
void WorkerManager::Del_Emp(){
    if(this->m_FileIsEmpty){
        cout <<"file does not exist or is empty"<<endl;
    }else{
        cout <<"enter the id to delete"<<endl;
        int id=0;
        cin >>id;
        int index=IsExist(id);
        if(index!=-1){
            for(int i=index;i<this->m_EmpNum-1;i++){
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            this->save();
            cout <<"success"<<endl;
        }else{
            cout <<"faile not fond"<<endl;
        }
    }
}
void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout <<"file does not exist or is empty"<<endl;
    }else{
        cout<<"enter the id to modify"<<endl;
        int id=0;
        cin >>id;
        int ret = this->IsExist(id);
        if(ret!=-1){
            delete this->m_EmpArray[ret];
            int newid =0;
            string newname="";
            int dselect=0;
            cout<<"fond "<<id<<"enter new id"<<endl;
            cin >> newid;
            cout <<"enter new name"<<endl;
            cin >> newname;
            cout <<"enter new department  1.employee  2.manager  3.boss"<<endl;
            cin >>dselect;
            Worker*worker=NULL;
            switch (dselect) {
                case 1:
                    worker = new Employee(newid,newname,dselect);
                    break;
                case 2:
                    worker = new Manager(newid,newname,dselect);
                    break;
                case 3:
                    worker = new Boss(newid,newname,dselect);
                    break;
                default:
                    break;
            }
            this->m_EmpArray[ret]=worker;
            cout <<"success"<<endl;
            this->save();
        }else{
            cout<<"not fond"<<endl;
        }
    }
}
void WorkerManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout <<"file does not exist or is empty"<<endl;
    }else{
        cout <<"enter the way to find  1.id  2.name "<<endl;
        int select=0;
        cin >>select;
        if(select==1){
            int id=0;
            cout <<"enter id"<<endl;
            cin>>id;
            int ret=IsExist(id);
            if(ret!=-1){
                cout <<"fond"<<endl;
                cout <<"information:"<<endl;
                this->m_EmpArray[ret]->showInfo();
            }
        }else if (select==2){
            string name;
            cout <<"enter name"<<endl;
            cin >> name;
            bool flag=false;
            for(int i=0;i<m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_name==name){
                    cout <<"found"<<endl;
                    cout <<"information"<<endl;
                    this->m_EmpArray[i]->showInfo();
                    flag=true;
                }
            }
            if(flag==false){
                cout <<"not found"<<endl;
            }
        }else{
            cout <<"error"<<endl;
        }
    }
}
void WorkerManager::sort_emp(){
    if(this->m_FileIsEmpty){
        cout <<"file does not exist or is empty"<<endl;
    }else{
        cout <<"please select sorting type"<<endl;
        cout <<"1.increase"<<endl;
        cout <<"2.decrease"<<endl;
        int select=0;
        cin >>select;
        for(int i=0;i<m_EmpNum;i++){
            int minOrmax=i;
            for(int j=i+1;j<m_EmpNum;j++){
                if(select==1){
                    if(this->m_EmpArray[minOrmax]->m_id>this->m_EmpArray[j]->m_id){
                        minOrmax=j;
                    }
                }else{
                    if(this->m_EmpArray[minOrmax]->m_id<this->m_EmpArray[j]->m_id){
                        minOrmax=j;
                    }
                }
            }
            if(i!=minOrmax){
                Worker*temp=this->m_EmpArray[i];
                this->m_EmpArray[i]=this->m_EmpArray[minOrmax];
                this->m_EmpArray[minOrmax]=temp;
            }
        }
        cout <<"success"<<endl;
        this->save();
        this->Show_Emp();
    }
}
void WorkerManager::Clean_File(){
    cout <<"are you serious?"<<endl;
    cout <<"1.yes 2.kidding"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<m_EmpNum;i++){
                delete m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
            }
            delete [] this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->m_EmpNum=0;
            this->m_FileIsEmpty=true;
        }
        cout <<"success"<<endl;
    }
}
WorkerManager::~WorkerManager(){
    if(this->m_EmpArray!=NULL){
        delete [] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}
