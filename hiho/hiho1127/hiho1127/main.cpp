//
//  main.cpp
//  hiho1127
//
//  Created by eycia on 3/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#define __maxNodes 2005
using namespace std;

vector<int> G[__maxNodes];
typedef vector<int>::iterator iterator_t;

int num_left;

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
    memset(matching, -1, sizeof(matching));
    for (int u = 1; u <= num_left; u++) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    int u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v+1000);
        G[v+1000].push_back(u);
        G[u+1000].push_back(v);
        G[v].push_back(u+1000);
    }
    num_left = n;
    cout << xyl_dfs() / 2 << endl;
    cout << (2 * n - xyl_dfs()) / 2 << endl;
    return 0;
}