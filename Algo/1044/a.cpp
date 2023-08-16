//
//  a.cpp
//  1044
//
//  Created by Haoyang Chen on 2022/6/15.
//

#include<iostream>
#include<vector>
#include<queue>
#include<float.h>
using namespace std;

struct node
{
    int to;
    double t0;
    node(int t, double t2)
    {
        to = t;
        t0 = t2;
    }
    bool operator<(const node& a)const
    {
        return t0 > a.t0;
    }
};

struct request
{
    int start;
    int end;
};


int m, e, n;
vector<double>* map;
vector<node>* path;
request* requests;
int edges_[400][400];
double alpha[20000];
int E_index[20000];
int cars_n[20000];

vector<int>** short_path(int s)
{
    double* u = new double[m];
    fill(u, u + m, DBL_MAX);
    bool* flag = new bool[m];
    fill(flag, flag + m, 0);
    vector<int>** n_ = new vector<int>*[m];
    for (int i = 0; i < m; i++)
        n_[i] = new vector<int>[1];
    priority_queue<node>q;

    u[s] = 0.;
    n_[s][0].push_back(s);
    q.push(node(s, 0.));
    while (!q.empty())
    {
        node t_ = q.top();
        q.pop();
        int k = t_.to;

        flag[k] = 1;

        for (int i = 0; i < path[k].size(); i++)
        {
            int nextN = path[k][i].to;
            double t1 = path[k][i].t0;
            if (!flag[nextN] && u[nextN] > u[k] + t1)
            {
                u[nextN] = u[k] + t1;
                q.push(node(nextN, u[nextN]));
                delete[]n_[nextN];
                n_[nextN] = new vector<int>[1];
                copy(n_[k], n_[k] + 1, n_[nextN]);
                n_[nextN][0].push_back(nextN);
            }
        }
    }
    delete[]u;
    delete[]flag;
    return n_;
}

bool update_path(int s, vector<int>* re, int** edge_f, bool* if_updata)
{
    bool flag = false;
    cout << re[0].size() * 2 - 1 << endl;
    int node = re[0].at(0);
    cout << node << " ";
    for (int i = 1; i < re[0].size(); i++)
    {
        int next_n = re[0].at(i);
        int edge_index = edges_[node][next_n];
        int index = E_index[edge_index];
        cout << edge_index << " " << next_n << " ";
        cars_n[edge_index]++;
        for (int j = 0; j < m; j++)
            ++edge_f[j][edge_index];
        if (edge_f[s][edge_index] > 10)
        {
            if_updata[s] = true;
            flag = true;
        }
        path[node][index].t0 = map[node][index] * (1 + alpha[edge_index] * (cars_n[edge_index] - 1));
        node = next_n;
    }
    cout << endl;
    return flag;
}

void Find_path()
{
    int** edge_f = new int* [m];
    for (int i = 0; i < m; i++)
    {
        edge_f[i] = new int[2 * e];
        fill(edge_f[i], edge_f[i] + 2 * e, 0);
    }
    bool* if_updata = new bool[m];
    fill(if_updata, if_updata + m, true);
    fill(cars_n, cars_n + 2 * e, 0);
    vector<int>*** re = new vector<int>**[m];
    for (int i = 0; i < m; i++)
        re[i] = NULL;

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int s = requests[i].start, t = requests[i].end;
        if (if_updata[s] || flag)
        {
            if (re[s] != NULL)
            {
                for (int j = 0; j < m; j++)
                    delete[]re[s][j];
                delete[]re[s];
            }
            re[s] = short_path(s);
            if_updata[s] = false;
            fill(edge_f[s], edge_f[s] + 2 * e, 0);
        }
        flag = update_path(s, re[s][t], edge_f, if_updata);
    }

    for (int i = 0; i < m; i++)
    {
        if (re[i] != NULL)
        {
            for (int j = 0; j < m; j++)
                delete[]re[i][j];
            delete[]re[i];
        }
        delete[]edge_f[i];
    }
        
    delete[]edge_f;
    delete[]re;
    delete[]if_updata;
}

int main()
{
    int iter;
    cin >> iter;
    for (int i = 0; i < iter; i++)
    {
        cin >> m >> e >> n;
        requests = new request[n];
        for (int j = 0; j < n; j++)
            cin >> requests[j].start >> requests[j].end;
        map = new vector<double>[m];
        path = new vector<node>[m];
        for (int j = 0; j < e; j++)
        {
            int u, v, e1 = 2 * j, e2 = 2 * j + 1;
            double t0, a1, a2;
            cin >> u >> v >> t0 >> a1 >> a2;
            map[u].push_back(t0);
            map[v].push_back(t0);
            path[u].push_back(node(v, t0));
            path[v].push_back(node(u, t0));
            edges_[u][v] = e1;
            edges_[v][u] = e2;
            E_index[e1] = (int)map[u].size() - 1;
            E_index[e2] = (int)map[v].size() - 1;
            alpha[e1] = a1;
            alpha[e2] = a2;
        }
        Find_path();

//        delete[]requests;
//        delete[]map;
//        delete[]path;
    }
    return 0;
}
