//
//  main.cpp
//  hdu1257
//
//  Created by eycia on 14-9-8.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

//
//  main.cpp
//  最大二分匹配
//
//  Created by eycia on 14-8-12.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#define __maxNodes 2010
using namespace std;

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
int num_left;
int num_right;
int num_edges;

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
    for (int u = 0; u < num_left; u++) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}

int solv(int t) {
    int temp[1005];
    for (int i = 0; i < 2010; i++) {
        G[i].clear();
    }
    
    for (int i = 0; i < t; i++) {
        cin >> temp[i];
    }
    for (int i = 0; i < t - 1; i++) {
        for (int j = i + 1; j < t; j++) {
            if (temp[i] >= temp[j]) {
                G[i].push_back(1000+j);
                G[1000+j].push_back(i);
            }
        }
    }
    num_left = t;
    return t - xyl_dfs();
}

int main() {
    int t;
    while (cin >> t) {
        cout << solv(t) << endl;
    }
    return 0;
}