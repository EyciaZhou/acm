//
//  main.cpp
//  poj2886
//
//  Created by eycia on 14/10/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef char name[15];
name ns[500005];
int ca[500005];
int pr[500005];

#define StartSeg

int Seg[2000000];
int l1, l2;
int tc;

#define lc(a) (a << 1)
#define rc(a) (a << 1 | 1)

void build(int n) {
    int tc = int(log(n + 0.0) / log(2.0) + 0.9999999) + 1;
    int r = 1 << (tc - 1);
    l1 = r;
    l2 = n;
    for (int i = r; i < r + n; i++) {
        Seg[i] = 1;
    }
    for (int i = r + n; i < 2 * r; i++) {
        Seg[i] = 0;
    }
    for (int i = r - 1; i > 0; i--) {
        Seg[i] = Seg[lc(i)] + Seg[rc(i)];
    }
}

int modify(int p, int d) {
    Seg[p]--;
    if (p >= l1) {
        return p - l1 + 1;
    }
    
    if (d <= Seg[lc(p)]) {
        return modify(lc(p), d);
    } else {
        return modify(rc(p), d - Seg[lc(p)]);
    }
}

#undef  StartSeg

void pre() {
    memset(pr, 0, sizeof(pr));
    for (int i = 1; i < 500005; i++) {
        for (int j = i; j < 500005; j += i) {
            pr[j] += 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, k;
    pre();
    
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%s %d", ns[i], &ca[i]);
        }
        build(n);
        int ma = -1;
        int mi = -1;
        for (int i = 1; i <= n; i++) {
            if (pr[i] > ma) {
                ma = pr[i];
                mi = i;
            }
        }
        int p = modify(1, k), now = k, rest = n;
        for (int i = 2; i <= mi; i++) {
            rest--;
            p = p + ca[now];
            if (ca[now] > 0) {
                p--;
            }
            p = p % rest;
            while (p <= 0) {
                p += rest;
            }
            while (p > rest) {
                p -= rest;
            }
            now = modify(1, p);
        }
        printf("%s %d\n", ns[now], ma);
    }
}
