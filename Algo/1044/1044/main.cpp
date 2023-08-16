//
//  main.cpp
//  1044
//
//  Created by Haoyang Chen on 2022/5/27.
//

#include <iostream>
#include <limits.h>
#include <math.h>
#include <stack>
using namespace std;

float t(int traffic,float alpha,float t_0){
    return t_0*(1+alpha*(traffic-1));
}

void navi(int m,int E,int n,int *D_start,int *D_dest,int *E_start,int *E_dest,float *t_0,float *alpha,float *alpha_){
    float map[m][m];
    int traffic[2*E];
    for(int i=0;i<2*E;i++)
        traffic[i]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
                map[i][j]=INT_MAX;
    for(int i=0;i<E;i++){
//        cout << E_start[i] <<" "<<E_dest[i]<<" "<<alpha[i]<<endl;
        map[E_start[i]][E_dest[i]]=alpha[i];
        map[E_dest[i]][E_start[i]]=alpha_[i];
    }
    for(int i=0;i<n;i++)
    {
        int s=D_start[i];
        int d=D_dest[i];
        int dp[m];
        int recordpath[m];
        bool fixed[m];
        for(int j=0;j<m;j++)
            recordpath[j]=s;
        for(int j=0;j<m;j++)
            fixed[j]=false;
        fixed[s]=true;
        for(int j=0;j<m;j++)
            dp[j]=INT_MAX;
        dp[s]=0;
        for(int j=0;j<E;j++){
            if(E_start[j]==s)
                dp[E_dest[j]]=t(traffic[2*(j)],alpha[j],t_0[j]);
            else if (E_dest[j]==s)
                dp[E_start[j]]=t(traffic[2*(j)+1],alpha_[j],t_0[j]);
        }
        for(int j=0;j<m-1;j++)
        {
            int minn=INT_MAX;
            int idx=0;
            for(int k=0;k<m;k++){
                if(k==s)
                    continue;
                if(!fixed[k] && dp[k]<minn){
                    minn=dp[k];
                    idx=k;
                }
            }
//            if(minn==INT_MAX)
//                break;
            fixed[idx]=true;
            for(int k=0;k<E;k++)
            {
                if(E_start[k]==idx){
                    if(dp[E_dest[k]]>minn+t(traffic[2*k], alpha[k], t_0[k])){
                        dp[E_dest[k]]=minn+t(traffic[2*(k)], alpha[k], t_0[k]);
                        recordpath[E_dest[k]]=idx;
                    }
                    continue;
                }
                else if (E_dest[k]==idx){
                    if(dp[E_start[k]]>minn+t(traffic[2*(k)+1],alpha_[k],t_0[k])){
                        dp[E_start[k]]=minn+t(traffic[2*(k)+1],alpha_[k],t_0[k]);
                        recordpath[E_start[k]]=idx;
                    }
                }
            }
        }
        int last=d;
        int length=1;
        stack<int> path;
        while(last!=s){
            for(int j=0;j<E;j++){
                if(E_start[j]==recordpath[last] && E_dest[j]==last){
                    path.push(last);
                    path.push(2*j);
                    path.push(recordpath[last]);
                    traffic[2*j]++;
                    length+=2;
                }
                else if (E_dest[j]==recordpath[last] && E_start[j]==last){
                    path.push(last);
                    path.push(2*j+1);
                    path.push(recordpath[last]);
                    traffic[2*j]++;
                    length+=2;
                }
            }
            last=recordpath[last];
        }
        cout << length << endl;
        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    int iter;
    cin >> iter;
    for (int i=0;i<iter;i++){
        int m,E,n;  //点数，边数，请求数
        cin >> m >> E >> n;
        int *D_start=new int[n],*D_dest=new int[n],*E_start=new int[E],*E_dest=new int[E];
        float *t_0=new float[E],*alpha=new float[E],*alpha_=new float[E];
        for(int j=0;j<n;j++)
            cin >> D_start[j] >> D_dest[j];
        for(int j=0;j<E;j++)
            cin >> E_start[j] >> E_dest[j] >> t_0[j] >> alpha[j] >> alpha_[j];
        cout <<endl;
        for(int j=0;j<E;j++){
            cout <<E_start[j]<<" "<<E_dest[j]<<" "<<alpha[j]<<endl;
        }
//        navi(m,E,n,D_start,D_dest,E_start,E_dest,t_0,alpha,alpha_);
    }
    return 0;
}


/*
 1
 16 20 3
 13 15
 0 14
 4 9
 0 1 34.70187337848428 0.049591918827111614 0.031115117755801558
 1 2 69.01985809637887 0.48726901441949955 0.37524390419797476
 1 5 25.070975479868352 0.22140478377272943 0.4321135885919023
 2 3 70.87714783754235 0.1635377843179563 0.34545425057208473
 2 6 30.66305472391232 0.1693570993756499 0.32687366811367863
 4 5 15.811529170621553 0.4180447788995118 0.12242169390849073
 4 8 33.77716612375613 0.01854430531331508 0.4158977756375563
 5 6 87.72605772145202 0.2644872444180956 0.18327405489430498
 5 9 28.898419441491342 0.15538787551320582 0.11479695368309722
 6 10 88.3909564852451 0.11540096850136528 0.2531737185071195
 7 11 25.77644411003788 0.23552362135713972 0.1580975695397009
 8 9 68.54441403184306 0.3471624977954888 0.2013379273759467
 9 13 46.27693042348048 0.20545307993335443 0.44803000397440645
 10 11 73.3329710629031 0.033533556595317926 0.20757939311837653
 10 14 79.68828429370515 0.09609848295500617 0.4258705100517581
 11 15 59.28973051262689 0.20966953102596497 0.4245064861080767
 12 13 8.531620316519483 0.14477913735744102 0.12127762569512884
 14 15 95.92613808979729 0.17887033160128296 0.12101078430259149
 9 4 30.07271575728908 0.37580196127967075 0.2154131496195013
 10 13 20.546610372924413 0.3720649106159346 0.015491421504829184
 */
