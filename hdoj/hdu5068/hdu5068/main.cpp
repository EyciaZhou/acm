//
//  main.cpp
//  hdu5068
//
//  Created by eycia on 9/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#define MOD 1000000007
#define lc(a) (a*2)
#define rc(a) (a*2+1)
#define ll long long
using namespace std;

bool stat[50005][2][2];
ll v[200005];

void build(int n, int l, int r) {
    if (l > r) return;
    if (l == r) {v[n] = 2; return;}
    build(lc(n), l, (l+r)/2);
    build(rc(n), (l+r)/2+1, r);
    //update
    v[n] = (v[lc(n)] * v[rc(n)]) % MOD;
}

void modify(int n, int l, int r, int lhs, int del) {
    if (l > r) return;
    if (l == r) {v[n] += del; return;}
    if (lhs <= (l+r)/2) {
        modify(lc(n), l, (l+r)/2, lhs, del);
    } else {
        modify(rc(n), (l+r)/2+1, r, lhs, del);
    }
    //update
    v[n] = (v[lc(n)] * v[rc(n)]) % MOD;
}

ll query(int n, int l, int r, int lhs, int rhs) {
    cout << l << " " << r << " " << lhs << " " << rhs << endl;
    if (l > r) return 1;
    if (l == r) {return v[n];}
    if (l == lhs && r == rhs) {return v[n];}
    if (rhs <= (l+r) / 2) {
        return query(lc(n), l, (l+r)/2, lhs, rhs);
    } else if (lhs > (l+r)/2) {
        return query(rc(n), (l+r)/2+1, r, lhs, rhs);
    } else {
        return query(lc(n), l, (l+r)/2, lhs, (l+r)/2) *
        query(rc(n), (l+r)/2+1, r, (l+r)/2+1, rhs);
    }
}

/*
4 3 2 1 0
*/

int main(int argc, const char * argv[]) {
    int n, m;
    int l, r;
    int x, y, z,o;
    while (scanf("%d%d", &n, &m) != EOF) {
        build(1, 1, n-1);
        memset(stat, true, sizeof(stat));
        for (int i = 0; i < m; i++) {
            scanf("%d", &o);
            if (o == 0) {
                scanf("%d%d", &l, &r);
                printf("%lld", query(1, 1, n-1, l, r-1));
            } else {
                scanf("%d%d%d", &x, &y, &z);
                if (stat[x][y-1][z-1]) {
                    stat[x][y-1][z-1] = false;
                    modify(1, 1, n-1, x, -1);
                } else {
                    stat[x][y-1][z-1] = true;
                    modify(1, 1, n-1, x, 1);
                }
            }
        }
    }
}
