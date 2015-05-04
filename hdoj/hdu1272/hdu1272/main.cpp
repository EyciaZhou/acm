//
//  main.cpp
//  hdu1272
//
//  Created by eycia on 14-9-21.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>

int fa[100005];
bool ex[100005];

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
    int a, b;
    bool flag;
    while (true) {
        for (int i = 0; i < 100005; i++) {
            fa[i] = i;
        }
        memset(ex, false, sizeof(ex));
        flag = false;
        while (true) {
            scanf("%d %d", &a, &b);
            if (a == -1 && b == -1) {
                return 0;
            }
            if (a == 0 && b == 0) {
                break;
            }
            ex[a] = true;
            ex[b] = true;
            if (!flag && getf(a) != getf(b)) {
                fa[fa[a]] = fa[b];
            } else {
                flag = true;
            }
        }
        if (!flag) {
            int ff;
            for (int i = 0; i < 100005; i++) {
                if (ex[i]) {
                    ff = getf(i);
                    break;
                }
            }
            for (int i = 0; i < 100005; i++) {
                if (ex[i]) {
                    getf(i);
                    if (fa[i] != ff) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (flag) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
}
