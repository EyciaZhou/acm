//
//  main.cpp
//  c
//
//  Created by eycia on 14-10-4.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

struct bian {
    int u, v;
} bians[100005];
bool bb[100005];

struct node {
    bool fl;
    int a, b;
} stack[100005];

int fa[100005];
bool ans[100005];

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
    int n, m, q;
    char c;
    int t1, t2;
    while (~scanf("%d %d %d", &n, &m, &q)) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &(bians[i].u), &(bians[i].v));
            bb[i] = true;
        }
        for (int i = 0; i < q; i++) {
            getchar();
            scanf("%c", &c);
            if (c == 'D') {
                scanf("%d", &t1);
                bb[t1] = false;
                stack[i].fl = true;
                stack[i].a = t1;
            }
            if (c == 'Q') {
                scanf("%d %d", &t1, &t2);
                stack[i].fl = false;
                stack[i].a = t1;
                stack[i].b = t2;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (bb[i]) {
                fa[getf(bians[i].u)] = getf(bians[i].v);
            }
        }
        int pa = -1;
        for (int i = q - 1; i >= 0; i--) {
            if (stack[i].fl) {
                fa[getf(bians[stack[i].a].u)] = getf(bians[stack[i].a].v);
            } else {
                if (getf(stack[i].a) == getf(stack[i].b)) {
                    ans[++pa] = true;
                } else{
                    ans[++pa] = false;
                }
            }
        }
        for (int i = pa; i >= 0; i--) {
            if (ans[i]) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
}
