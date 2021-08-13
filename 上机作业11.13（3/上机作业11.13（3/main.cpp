//
//  main.cpp
//  上机作业11.13（3
//
//  Created by Haoyang Chen on 2020/11/13.
//

#include <iostream>
using namespace std;
class Timedate{
public:
    int year,month,day,hr,min,sec;
    void timeSet(int y,int m,int d,int h,int m2,int s){
        year = y;
        month = m;
        day = d;
        hr = h;
        min = m2;
        sec = 2;
    }
    void timeOut(){
        cout << year << month << day << hr << min << sec <<endl;
    }
};
int main(int argc, const char * argv[]) {
    Timedate time;
    time.timeSet(2020, 11, 13, 10, 33, 57);
    time.timeOut();
    return 0;
}
