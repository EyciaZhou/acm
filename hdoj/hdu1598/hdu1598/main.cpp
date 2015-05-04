//
//  main.cpp
//  hdu1598
//
//  Created by eycia on 14-9-22.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct bian {
    int u, v;
    int w;
} bians[1005];

struct Comparator {
    inline bool operator()(const bian& s1, const bian& s2) const {
        return s1.w < s2.w;
    }
};

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

int main() {
    int n, m;
    int start, end, low, ans;
    while (cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            cin >> bians[i].u >> bians[i].v >> bians[i].w;
        }
        sort(bians, bians + m, Comparator());
        int q;
        cin >> q;
        while (q--) {
            cin >> start >> end;
            ans = 10000000;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j <= n; j++) {
                    fa[j] = j;
                }
                low = -1;
                for (int j = i; j < m; j++) {
                    fa[getf(bians[j].u)] = getf(bians[j].v);
                    if (getf(start) == getf(end)) {
                        low = bians[j].w;
                        break;
                    }
                }
                if (low >= 0) {
                    if (low - bians[i].w < ans) {
                        ans = low - bians[i].w;
                    }
                }
            }
            if (ans == 10000000) {
                cout << -1 << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
}