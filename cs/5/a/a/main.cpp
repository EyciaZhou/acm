//
//  main.cpp
//  a
//
//  Created by eycia on 14/11/1.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

#define lc(a) ((a) << 1)
#define rc(a) ((a) << 1 | 1)

int Seg[80000];
int Laz[80000];
int ml[80000];
int mr[80000];
int l1, l2;

void modify(int p, int l, int r, int v) {
    if (p >= l1) {
        Laz[p] += v;
        return;
    }
    if (l == ml[lc(p)] && r == mr[rc(p)]) {
        Laz[p] += v;
        return;
    }
    
    if (l >= ml[rc(p)]) {
        modify(rc(p), l, r, v);
    } else  if (r <= mr[lc(p)]) {
        modify(lc(p), l, r, v);
    } else {
        modify(lc(p), l, mr[lc(p)], v);
        modify(rc(p), ml[rc(p)], r, v);
    }
}

int main(int argc, const char * argv[]) {
    int n, m, q;
    int l, r, v;
    while (scanf("%d %d %d", &n, &m, &q) != EOF) {
        int f = (1 << int(log(n+0.0) / log(2.0) + 0.9999999));
        l1 = n;
        l2 = f;
        for (int i = 1; i <= 2*n; i++) {
            Seg[i] = 0;
            Laz[i] = 0;
        }
        for (int i = l2; i < l2 + l1; i++) {
            ml[i] = mr[i] = i - l2 + 1;
        }
        for (int i = l2 - 1; i >= 1; i--) {
            ml[i] = ml[lc(i)];
            mr[i] = ml[rc(i)];
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &l, &r, &v);
            modify(1, l, r, v);
        }
        for (int i = 1; i < 2 * n; i++) {
            Laz[lc(i)] += Laz[i];
            Laz[rc(i)] += Laz[i];
        }
        
    }
}
