//
//  main.cpp
//  tarjan
//
//  Created by eycia on 14-9-23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> g[10005];   //grah
int dfn[10005];         //first visit time
int low[10005];         //the low visit time
int belong[10005];      //the point's belong at last
int nn[10005];          //the child point number in the big point
int ind;                //time
bool v[10005];          //visited
bool sta[10005];        //in stack

stack<int> ss;          //the stack
int num = 0;            //the big point's No

void tarjan(int u) {
    dfn[u] = low[u] = ++ind;
    ss.push(u);
    sta[u] = true;
    v[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        if (!v[g[u][i]]) {
            tarjan(g[u][i]);
            low[u] = min(low[u], low[g[u][i]]);
        } else if (sta[g[u][i]]) {
            low[u] = min(low[u], dfn[g[u][i]]);
        }
    }
    if (dfn[u] == low[u]) {
        int p, k = 0;
        num++;
        do {
            k++;
            p = ss.top();
            ss.pop();
            belong[p] = num;
            sta[p] = false;
        } while (p != u);
        nn[num] = k;
    }
}