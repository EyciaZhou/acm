//
//  main.cpp
//  bczm2ac
//
//  Created by eycia on 25/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define __maxNodes 2005
using namespace std;

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

int nu[1005];

bool gl(int l, int r) {
    if (l > r) swap(l, r);
    if (r % l != 0) return false;
    int li = sqrt(r / l);
    int ta = r / l;
    for (int i = 2; i <= li; i++) {
        if (ta % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for (int ff = 1; ff <= t; ff++) {
        cout << "Case #" << ff << ": ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nu[i];
        }
        for (int i = 0; i <= n; i++) {
            G[i].clear();
        }
        num_left = n;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (gl(nu[i], nu[j])) {
                    //G[i].push_back(j+1000);
                    //G[j].push_back(i+1000);
                    
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        int a = xyl_dfs();
        cout << n - a << endl;
    }
}