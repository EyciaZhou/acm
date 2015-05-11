//
//  main.cpp
//  cf25c
//
//  Created by eycia on 11/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long

inline int rd(int &n) {
    return scanf("%d", &n);
}

#define rd(a) scanf("%d", &(a))

int mat[305][305];

int main(int argc, const char * argv[]) {
    int n, k;
    int u, v, w;
    rd(n);
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            rd(mat[i][j]);
            if (i <= j) {
                tot += (ll)mat[i][j];
            }
        }
    }
    rd(k);
    for (int q = 1; q <= k; q++) {
        rd(u);rd(v);rd(w);
        if (mat[u][v] <= w) {
            cout << tot << endl;
            continue;
        }
        mat[u][v] = mat[v][u] = w;
        
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mat[i][j] = min(mat[i][j], mat[i][u] + w + mat[v][j]);
                mat[i][j] = min(mat[i][j], mat[i][v] + w + mat[u][j]);
            }
        }
        
        
        tot = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                tot += (ll)mat[i][j];
            }
        }
        cout << tot << " ";
    }
}
