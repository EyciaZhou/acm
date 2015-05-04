//
//  main.cpp
//  zoj1239
//
//  Created by eycia on 14-9-3.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;
/*
#include <vector>
#include <cmath>
#define __maxNodes 100000
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


int solv(int n) { // n-> max number
    for (int i = 0; i < __maxNodes; i++) {
        G[i].clear();
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (sqrt(i + j) - int(sqrt(i + j)) < 0.000001) {
                G[i].push_back(j + 5000);
                G[j + 5000].push_back(i);
            }
        }
    }
    num_left = n;
    return n - xyl_dfs();
}

int main(int argc, const char * argv[]) {
    int ff, n;
    int k = 0;
    for (int i = 1; i < 1500; i++) {
        int t = solv(i);
        if (t != k) {
            cout << "   " << i - 1 << "," << endl;
            k = t;
        }
    }
    cin >> ff;
    while (ff--) {
        cin >> n;
        cout << solv(n);
    }
}
*/

int re[55] =  {
 0,
 1,
 3,
 7,
 11,
 17,
 23,
 31,
 39,
 49,
 59,
 71,
 83,
 97,
 111,
 127,
 143,
 161,
 179,
 199,
 219,
 241,
 263,
 287,
 311,
 337,
 363,
 391,
 419,
 449,
 479,
 511,
 543,
 577,
 611,
 647,
 683,
 721,
 759,
 799,
 839,
 881,
 923,
 967,
 1011,
 1057,
 1103,
 1151,
 1199,
 1249,
 1299,
 1351,
 1403,
 1457
};

int main() {
    int tt, t;
    cin >> tt;
    while (tt--) {
        cin >> t;
        cout << re[t] << endl;
    }
}

