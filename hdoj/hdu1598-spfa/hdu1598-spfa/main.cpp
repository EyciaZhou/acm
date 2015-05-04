//
//  main.cpp
//  hdu1598-spfa
//
//  Created by eycia on 14-9-23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct bian {
    int u, v;
    int w;
} bians[1005];

int n, m;
int mi, ma;
int st, en;

int fa[205];

inline int getf(int s) {
    if (fa[s] == s) {
        return s;
    }
    int t = s;
    while (fa[t] != t) {
        t = fa[t];
    }
    fa[s] = t;
    while (fa[s] != s) {
        s = fa[s];
        fa[s] = t;
    }
    return t;
}

bool bcj(int min, int max) {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        if (bians[i].w <= max && bians[i].w >= min) {
            fa[getf(bians[i].u)] = getf(bians[i].v);
            if (getf(st) == getf(en)) {
                return true;
            }
        }
    }
    return false;
}

inline bool erfenfunc(int e) {
    for (int i = mi; i <= ma - e; i++) {
        if (bcj(i, i + e)) {
            return true;
        }
    }
    return false;
}

int erfen(int lhs, int rhs) {
    //lhs !ok, rhs ok
    if (rhs - lhs <= 1) {
        return rhs;
    }
    int mid = (lhs + rhs) / 2;
    if (erfenfunc(mid)) {
        return erfen(lhs, mid);
    } else {
        return erfen(mid, rhs);
    }
}

int main(int argc, const char * argv[]) {
    int q;
    while (cin >> n >> m) {
        mi = 2000000000;
        ma = -1;
        for (int i = 0; i < m; i++) {
            cin >> bians[i].u >> bians[i].v >> bians[i].w;
            if (bians[i].w > ma) {
                ma = bians[i].w;
            }
            if (bians[i].w < mi) {
                mi = bians[i].w;
            }
        }
        cin >> q;
        while (q--) {
            cin >> st >> en;
            cout << erfen(-1, ma - mi) << endl;
        }
    }
}
