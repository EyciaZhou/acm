//
//  main.cpp
//  hdu1829-dfs
//
//  Created by eycia on 14-9-21.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> G[2004];
int v[2004];
bool flag;

void dfs(int now, int p) {
    v[now] = p;
    for (int i = 0; i < G[now].size(); i++) {
        if (v[G[now][i]] == p) {
            flag = true;
        }
        if (flag) {
            return;
        }
        if (v[G[now][i]] == 3) {
            dfs(G[now][i], 1-p);
        }
    }
}

int main(int argc, const char * argv[]) {
    int ff;
    int bugs, inters;
    int a, b;
    cin >> ff;
    for (int tt = 1; tt <= ff; tt++) {
        for (int i = 0; i < 2004; i++) {
            v[i] = 3;
            G[i].clear();
        }
        scanf("%d %d", &bugs, &inters);
        for (int i = 0; i < inters; i++) {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        flag = false;
        for (int i = 0; i < bugs; i++) {
            if (v[i] == 3 && !flag) {
                dfs(i, 0);
            }
        }
        printf("Scenario #%d:\n", tt);
        if (flag) {
            printf("Suspicious bugs found!\n");
        } else {
            printf("No suspicious bugs found!\n");
        }
        printf("\n");
    }
}
