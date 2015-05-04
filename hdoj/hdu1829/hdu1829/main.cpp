//
//  main.cpp
//  hdu1829
//
//  Created by eycia on 14-9-21.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int fa[4005];

inline int getf(int s) {
    int t = s;
    while (fa[t] != t) {
        t = fa[t];
    }
    while (fa[s] != s) {
        s = fa[s];
        fa[s] = t;
    }
    return t;
}

int main(int argc, const char * argv[]) {
    int ff;
    int bugs, inters;
    int a, b;
    cin >> ff;
    for (int tt = 1; tt <= ff; tt++) {
        for (int i = 0; i < 4005; i++) {
            fa[i] = i;
        }
        scanf("%d %d", &bugs, &inters);
        bool flag = false;
        for (int i = 0; i < inters; i++) {
            scanf("%d %d", &a, &b);
            if (getf(a) == getf(b)) {
                flag = true;
            }
            fa[getf(a)] = getf(b+2001);
            fa[getf(a+2001)] = getf(b);
        }
        printf("Scenario #%d:\n", tt);
        if (flag) {
            printf("Suspicious bugs found!\n");
        } else {
            printf("No suspicious bugs found!\n");
        }
        printf("\n");
    }
}
