 //
//  main.cpp
//  poj2513
//
//  Created by eycia on 14/12/6.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>

struct trno {
    int n[26];
    int v;
} tr[250015 * 11 * 2];

int mem, me;

int g[500010];

int fa[500010];

inline int insert(char *st) {
    int k = 0;
    for (int i = 0; i < strlen(st); i++) {
        if (tr[k].n[st[i] - 'a'] == -1) {
            tr[k].n[st[i] - 'a'] = ++mem;
            memset(tr[mem].n, -1, sizeof(tr[mem].n));
            tr[mem].v = -1;
        }
        k = tr[k].n[st[i] - 'a'];
    }
    if (tr[k].v == -1) {
        tr[k].v = ++me;
    }
    return tr[k].v;
}

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
    char st1[15], st2[15];
    int x, y;
    mem = 0;
    me = -1;
    memset(tr[0].n, -1, sizeof(tr[0].n));
    tr[0].v = -1;
    for (int i = 0; i < 500010; i++) {
        fa[i] = i;
    }
    while (scanf("%s %s", st1, st2) != EOF) {
        x = insert(st1);
        y = insert(st2);
        g[x]++;
        g[y]++;
        if (getf(x) != getf(y)) {
            fa[getf(x)] = getf(y);
        }
    }
    int fl_n = 0, odd_po_n = 0;
    for (int i = 0; i <= me; i++) {
        if (fa[i] == i) {
            fl_n++;
        }
    }
    if (fl_n > 1) {
        printf("Impossible\n");
    } else {
        for (int i = 0; i <= me; i++) {
            if (g[i] % 2) {
                odd_po_n++;
            }
        }
        if (!odd_po_n || odd_po_n == 2) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }
}
