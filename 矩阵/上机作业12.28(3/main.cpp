//
//  main.cpp
//  上机作业12.28(3
//
//  Created by Haoyang Chen on 2020/12/28.
//

#include <iostream>
using namespace std;
class mat{
public:
    int m,n,l;
    int ***p;
    void set(int m,int n,int l){
        this->m=m;
        this->n=n;
        this->l=l;
        p= new int**[m];
        
        for(int i=0;i<m;i++)
            p[i]=new int*[n];

        for( int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                p[i][j]=new int[l];

        for( int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                for(int k=0; k<l; k++)
                    p[i][j][k]=10;
    }
    void setele(int i,int j,int k,int num){
        p[i][j][k]=num;
    }
    void show(){
        for(int i=0;i<m;i++){
            cout << "层"<<i<<endl;
            for(int j=0;j<n;j++){
                for(int k=0;k<l;k++){
                    cout <<p[i][j][k]<<" ";
                }
                cout <<endl;
            }
        }
    }
    void findmax(){
        int max=p[0][0][0];
        int mm=0;
        int nn=0;
        int ll=0;
        for(int i=0;i<2;i++){
            for(int m=0;m<2;m++){
                for(int n=0;n<2;n++){
                    if(p[i][m][n]>max){
                        max=p[i][m][n];
                        mm=i;
                        nn=m;
                        ll=n;
                    }
                }
            }
        }
        cout << "最大的数为"<<max<<"  location: （"<<mm<<","<<nn<<","<<ll<<")"<<endl;
    }
};
int main(int argc, const char * argv[]) {
    mat m1;
    m1.set(2, 2, 2);
    for(int i=0;i<2;i++){
        for(int m=0;m<2;m++){
            for(int n=0;n<2;n++){
                int temp;
                cout <<"输入"<<i<<"行"<<m<<"列"<<n<<"层的数"<<endl;
                cin >> temp;
                m1.setele(i, m, n, temp);
            }
        }
    }
    m1.show();
    m1.findmax();
    return 0;
}
