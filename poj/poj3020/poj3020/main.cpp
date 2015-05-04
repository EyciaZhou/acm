//
//  main.cpp
//  poj3020
//
//  Created by eycia on 14-8-12.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#define __maxNodes 500
using namespace std;
int si[4] = {0, 1, 0, -1};
int sj[4] = {1, 0, -1, 0};

struct Edge {
    int from;
    int to;
    
    Edge(int f, int t) {
        this->from = f;
        this->to = t;
    }
};

vector<int> G[__maxNodes];
typedef vector<int>::iterator iterator_t;

int num_nodes;

int matching[__maxNodes];
int check[__maxNodes];

bool dfs(int u) {
    for (iterator_t i = G[u].begin(); i != G[u].end(); i++) {
        int v = *i;
        if (!check[v]) {
            check[v] = true;
            if (matching[v] < 0 || dfs(matching[v])) {
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false;
}

int xyl_dfs() {
    int ans = 0;
    for (int i = 0; i < __maxNodes; i++) {
        matching[i] = -1;
    }
    memset(matching, -1, sizeof(matching));
    for (int u = 0; u < __maxNodes; u++) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}

int ha(int i, int j) {
    return i * 11 + j;
}

bool mmap[45][15];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    for (int t = 0; t < ff; t++) {
        for (int i = 0; i < __maxNodes; i++) {
            G[i].clear();
        }
        memset(mmap, false, sizeof(mmap));
        int n, m;
        scanf("%d %d", &n, &m);
        num_nodes = 0;
        for (int i = 1; i <= n; i++) {
            getchar();
            for (int j = 1; j <= m; j++) {
                if (getchar() == '*') {
                    mmap[i][j] = true;
                    num_nodes++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!mmap[i][j]) continue;
                for (int k = 0; k < 4; k++) {
                    if (mmap[i + si[k]][j + sj[k]]) {
                        G[ha(i, j)].push_back(ha(i + si[k], j + sj[k]));
                    }
                }
            }
        }
        printf("%d\n", num_nodes - xyl_dfs());
    }
}
