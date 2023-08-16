//
//  main.cpp
//  1445
//
//  Created by Haoyang Chen on 2022/6/17.
//

#include<algorithm>
#include<cmath>
#include <iostream>
#include<fstream>
#include<stack>
#define pi 3.14159265
using namespace std;

enum Index { MinusOne, Zero, One };

struct Xy
{
    int x;
    int y;
    int change;

    Xy()
    {
        x = 0;
        y = 0;
        change = 0;
    }

    Xy(int a, int b, int c)
    {
        x = a;
        y = b;
        change = c;
    }
};

bool** map = new bool* [1000];

int current_f = 0;

int v[8];

const Xy moveXy[8] = { Xy(1,0,0),Xy(1,1,0),Xy(0,1,0),Xy(-1,1,0),Xy(-1,0,0),Xy(-1,-1,0),Xy(0,-1,0),Xy(1,-1,0) };

const int need[3] = { 3,0,6 };

const int direction[3][3] = { {5,4,3},{6,8,2},{7,0,1} };

void view()
{
    cout << 3 << endl;

    string viewpoint;
    cin >> viewpoint;
    int i_bin;

    for (int i = 0; i < 8; i++)
    {
        i_bin = (int)viewpoint[i];
        v[i] = i_bin - 48;
    }
}

void change_act(int action)
{
    if (action == 0)
    {
        cout << 0 << endl;
        current_f = (current_f + 1) % 8;
    }
    else if (action == 1)
    {
        cout << 1 << endl;
        current_f = (current_f + 7) % 8;
    }
    else
    {
        cout << 0 << endl;
        current_f = (current_f + 1) % 8;
    }
}

void back_node(Xy current_, Xy top_)
{
    int x = top_.x - current_.x, y = top_.y - current_.y;
    int xi = 0, yi = 0;
    switch (x)
    {
    case -1:
        xi = MinusOne;
        break;
    case 0:
        xi = Zero;
        break;
    case 1:
        xi = One;
        break;
    default:
        break;
    }

    switch (y)
    {
    case -1:
        yi = MinusOne;
        break;
    case 0:
        yi = Zero;
        break;
    case 1:
        yi = One;
        break;
    default:
        break;
    }
    int top_f = direction[xi][yi];
    int action_ = 0;
    int iter = abs(current_f - top_f), sgn = current_f - top_f;
    if ((sgn > 0 && iter < 4) || (sgn < 0 && iter>4))
        action_ = 1;
    if (iter > 4)
        iter = 8 - iter;
    for (int i = 0; i < iter; i++)
        change_act(action_);
}

bool compute_next_node(Xy current_, int index)
{
    int xr = 0, yr = 0;
    int x = current_.x, y = current_.y;
    int d = current_f;
    if (index == 0)
    {
        xr = x + moveXy[d].x;
        yr = y + moveXy[d].y;
    }
    else if (index == 1)
    {
        xr = x + moveXy[(d + 1) % 8].x;
        yr = y + moveXy[(d + 1) % 8].y;
    }
    else if (index == 2)
    {
        xr = x + moveXy[(d + 7) % 8].x;
        yr = y + moveXy[(d + 7) % 8].y;
    }
    if (xr < 0 || yr < 0)return true;
    return map[xr][yr];
}

void action()
{
    int finish = 0;
    stack<Xy>temp;
    Xy current_;
    temp.push(Xy(0, 0, 0));
    map[0][0] = true;

    int if_next = 0;
    while (!temp.empty())
    {
        current_ = temp.top();
        if (if_next >= 3)
        {
            if_next = 0;
            temp.pop();
            if (temp.empty())break;
            Xy top_ = temp.top();
            back_node(current_, top_);
            cout << 2 << endl;
            cin >> finish;
        }
        else
        {
            view();
            int t = -1;
            for (int i = 0; i < 3; i++)
                if (v[need[i]] == 0 && !compute_next_node(current_, i))
                {
                    t = i;
                    break;
                }
            if (t == 0)
            {
                if_next = 0;
                cout << 2 << endl;
                cin >> finish;
                Xy te(current_.x + moveXy[current_f].x, current_.y + moveXy[current_f].y, 0);
                temp.push(te);
                map[te.x][te.y] = true;
            }
            else if (t == 1)
            {
                if_next = 0;
                change_act(0);
                cout << 2 << endl;
                cin >> finish;
                Xy te(current_.x + moveXy[current_f].x, current_.y + moveXy[current_f].y, 0);
                temp.push(te);
                map[te.x][te.y] = true;
            }
            else if (t == 2)
            {
                if_next = 0;
                change_act(1);
                cout << 2 << endl;
                cin >> finish;
                Xy te(current_.x + moveXy[current_f].x, current_.y + moveXy[current_f].y, 0);
                temp.push(te);
                map[te.x][te.y] = true;
            }
            else
            {
                if_next++;
                if (if_next <= 2)
                    for (int i = 0; i < if_next + 1; i++)
                        change_act(0);
            }
            
        }
        if (finish == 1)break;
    }
}

int main()
{
    srand((int)time(0));
    int map_num;
    cin >> map_num;
    for (int i = 0; i < map_num; i++)
    {
        current_f = 0;
        for (int i = 0; i < 1000; i++)
        {
            map[i] = new bool[1000];
            fill(map[i], map[i] + 1000, false);
        }
        action();
    }

    return 0;
}

