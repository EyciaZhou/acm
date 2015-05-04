//
//  main.cpp
//  poj3216
//
//  Created by eycia on 14-9-6.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

//
//  最大二分匹配
//
//  Created by eycia on 14-8-12.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#define __maxNodes 500
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

int dis[25][25];
int place[205], dur[205], ar[205];

int floyd_num;

void floyd() {
    for (int k = 1; k <= floyd_num; k++) {
        for (int i = 1; i <= floyd_num; i++) {
            if (dis[i][k] < 1) continue;
            for (int j = 0; j <= floyd_num; j++) {
                if (dis[k][j] < 0) continue;
                if (dis[i][j] < 0 || (dis[i][j] > dis[i][k] + dis[k][j])) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int q, m;
    while (1) {
        cin >> q >> m;
        if (q == 0 && m == 0) {
            break;
        }
        for (int i = 0; i < __maxNodes; i++) {
            G[i].clear();
        }
        for (int i = 1; i <= q; i++) {
            for (int j = 1; j <= q; j++) {
                cin >> dis[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> place[i] >> ar[i] >> dur[i];
        }
        floyd_num = q;
        floyd();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                if (ar[i] >= ar[j] + dis[place[i]][place[j]] + dur[j]) {
                    G[i].push_back(j + 200);
                    G[j + 200].push_back(i);
                }
            }
        }
        num_left = m;
        cout << m - xyl_dfs() << endl;
    }
}
