//
//  main.cpp
//  上机作业12.14(1
//
//  Created by Haoyang Chen on 2020/12/14.
//

#include <iostream>
#define max 20
using namespace std;
class student{
public:
    int sno,math,eng,phy;
    char str[20];
};
class seuclass{
public:
    student st[max];
    int last;
    seuclass(){
        last=-1;
    }
    void setinfo(int sno,student s){
        last++;
        cout <<"name set:"<<endl;
        cin >> s.str;
        cout <<"math grade set:"<<endl;
        cin >> s.math;
        cout <<"english grade set:"<<endl;
        cin >> s.eng;
        cout <<"physics grade set:"<<endl;
        cin >> s.phy;
        st[last]=s;
    }
    void findmax(){
        student temp;
        temp=st[0];
        for(int m=0;m<last;m++){
            if((st[m].eng+st[m].math+st[m].phy)/3<(st[m+1].eng+st[m+1].math+st[m+1].phy)/3){
                temp=st[m+1];
            }
        }
        cout << "the student who has the max average grade is:"<<temp.str<<endl;
    }
    void sort(){
        for(int m = 0;m<last;m++){
            for(int n=0;n<last-m-1;n++){
                if((st[m].eng+st[m].math+st[m].phy)/3<(st[m+1].eng+st[m+1].math+st[m+1].phy)/3){
                    student temp=st[m];
                    st[m]=st[m+1];
                    st[m+1]=temp;
                }
            }
        }
        cout <<"sorted:"<<endl;
        for(int m=0;m<=last;m++){
            cout << st[m].str<<"  ";
        }
    }
    void find(){
        cout <<"what kind of grade are you going to use?"<<endl;
        cout <<"math: 0  physics: 1  english: 2"<<endl;
        int type;
        while(1){
            cin >> type;
            if(type>-1&&type<3)break;
            cout <<"invalid!! enter the given number"<<endl;
        }
        int grade;
        cout <<"enter the grade"<<endl;
        cin >> grade;
        switch (type) {
            case 0:
                for(int m=0;m<=last;m++){
                    if(st[m].math==grade){
                        cout <<"founded  student:"<<st[m].str<<"   number:"<<st[m].sno<<endl;
                    }
                }
                break;
            case 1:
                for(int m=0;m<=last;m++){
                    if(st[m].phy==grade){
                        cout <<"founded  student:"<<st[m].str<<"   number:"<<st[m].sno<<endl;
                    }
                }
                break;
            case 2:
                for(int m=0;m<=last;m++){
                    if(st[m].eng==grade){
                        cout <<"founded  student:"<<st[m].str<<"   number:"<<st[m].sno<<endl;
                    }
                }
                break;
            default:
                break;
        }
    }
};
int main(int argc, const char * argv[]) {
    seuclass wjxclass;
    student a,b,c;
    int number=61620101;
    wjxclass.setinfo(number++, a);
    wjxclass.setinfo(number++, b);
    wjxclass.setinfo(number++, c);
    wjxclass.sort();
    wjxclass.findmax();
    wjxclass.find();
    return 0;
}
