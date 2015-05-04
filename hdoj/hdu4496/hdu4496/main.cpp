//
//  main.cpp
//  hdu4496
//
//  Created by eycia on 14/10/19.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

struct bian {
    int u, v;
} bians[100005];

int ans[100005];

int fa[100005];

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

int main(int argc, const char * argv[]) {
    int n, m;
    char c;
    int t1, t2;
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &t1, &t2);
            bians[i].u = t1;
            bians[i].v = t2;
        }
        int p = 0;
        int tot = n;
        for (int i = m; i > 0; i--) {
            ans[p] = tot;
            p++;
            if (getf(bians[i].u) != getf(bians[i].v)) {
                tot--;
                fa[getf(bians[i].u)] = getf(bians[i].v);
            }
        }
        for (int i = p - 1; i >= 0; i--) {
            printf("%d\n", ans[i]);
        }
    }
}

