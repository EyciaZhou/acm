//
//  main.cpp
//  cf505d
//
//  Created by eycia on 15/1/23.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int fa[100005];
vector<int> g[100005];
bool vis[100005];
bool hh[100005];

int getf(int v) {
    return fa[v] == v ? v : fa[v] = getf(fa[v]);
}

int dfn[100005];         //first visit time
int low[100005];         //the low visit time
int belong[100005];      //the point's belong at last
int nn[100005];          //the child point number in the big point
int ind;                //time
//bool v[100005];          //visited
bool sta[100005];        //in stack

stack<int> ss;          //the stack
int num = 0;            //the big point's No

void tarjan(int u) {
    dfn[u] = low[u] = ++ind;
    ss.push(u);
    sta[u] = true;
    vis[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        if (!vis[g[u][i]]) {
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

int main(int argc, const char * argv[]) {
    int n, m;
    int u, v;
    
    memset(vis, false, sizeof(vis));
    memset(hh, false, sizeof(hh));
    
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        if (getf(u) != getf(v)) {
            fa[getf(u)] = getf(v);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        getf(i);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ind = 0;
            num = 0;
            tarjan(i);
            if (ind != num) {
                hh[fa[i]] = true;
            }
        }
    }
    int tot = 0, block = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) {
            if (hh[i]) {
                tot ++;
            }
            block++;
        }
    }
    cout << n + tot - block << endl;
}
