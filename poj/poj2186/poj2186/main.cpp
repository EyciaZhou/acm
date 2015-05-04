//
//  main.cpp
//  poj2186
//
//  Created by eycia on 14-9-1.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

vector<int> g[10005];
int dfn[10005];
int low[10005];
int belong[10005];
int nn[10005];
int outd[10005];
int ind;
bool v[10005];
bool sta[10005];

stack<int> ss;
int num = 0;

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

int main(int argc, const char * argv[]) {
    int n, m;
    int x, y;
    memset(v, false, sizeof(v));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    ind = 0;
    num = 0;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (belong[g[i][j]] == belong[i]) continue;
            outd[belong[i]]++;
        }
    }
    int k = 0, p = 0;
    for (int i = 1; i <= num; i++) {
        if (!outd[i]) {
            k++;
            p = i;
        }
    }
    if (k > 1) {
        cout << 0;
    } else {
        cout << nn[p];
    }
}
