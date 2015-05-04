//
//  main.cpp
//  hdu1754
//
//  Created by eycia on 14/10/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

#define lc(a) ((a) << 1)
#define rc(a) ((a) << 1 | 1)

int Seg[600000];
int l1, l2;

void modify(int p, int x, int y, int pos, int v) {
    if (p >= l2) {
        Seg[p] = v;
        return ;
    }
    if (v > Seg[p]) {
        Seg[p] = v;
    }
    int m = (x + y) / 2;
    if (pos <= m) {
        modify(lc(p), x, m, pos, v);
    } else {
        modify(rc(p), m + 1, y, pos, v);
    }
}

int sum(int p, int x, int y, int l, int r) {
    //cout << x << " " << y << " " << l << " " << r << endl;
    if (p > l2) {
        return Seg[p];
    }
    if (x == l && y == r) {
        return Seg[p];
    }
    int m = (x + y) / 2;
    if (r <= m) {
        return sum(lc(p), x, m, l, r);
    } else if (l >= m + 1) {
        return sum(rc(p), m+1, y, l, r);
    } else {
        return max( sum(lc(p), x, m, l, m), sum(rc(p), m+1, y, m+1, r) );
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    char ch;
    int v1, v2;
    //BIT bit;
    while (scanf("%d %d", &n, &m) != EOF) {
        int f = (1 << int(log(n+0.0) / log(2.0) + 0.9999999));
        l1 = n;
        l2 = f;
        
        for (int i = f; i < f + n; i++) {
            scanf("%d", &Seg[i]);
        }
        for (int i = f - 1; i >= 1; i--) {
            Seg[i] = max(Seg[lc(i)], Seg[rc(i)]);
        }
        
        for (int i = 1; i <= m; i++) {
            getchar();
            scanf("%c %d %d", &ch, &v1, &v2);
            if (ch == 'Q') {
                printf("%d\n", sum(1, 1, l2, v1, v2));
            } else {
                modify(1, 1, l2, v1, v2);
            }
        }
    }
}
