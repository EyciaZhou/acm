//
//  main.cpp
//  hdu5068
//
//  Created by eycia on 9/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#define MOD 1000000007
#define lc(a) (a*2)
#define rc(a) (a*2+1)
#define ll long long
using namespace std;

struct mat{
    ll a[2][2];
    mat(ll a1, ll a2, ll b1, ll b2) {
        a[0][0] = a1;
        a[0][1] = a2;
        a[1][0] = b1;
        a[1][1] = b2;
    }
    mat() {
        a[0][0] = 0;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = 0;
    }
};

mat one = mat(1, 0, 0, 1);
mat all = mat(1, 1, 1, 1);

mat operator*(const mat &l, const mat &r) {
    return mat((l.a[0][0]*r.a[0][0]+l.a[0][1]*r.a[1][0])%MOD, (l.a[0][0]*r.a[0][1]+l.a[0][1]*r.a[1][1])%MOD,
               (l.a[1][0]*r.a[0][0]+l.a[1][1]*r.a[1][0])%MOD, (l.a[1][0]*r.a[0][1]+l.a[1][1]*r.a[1][1])%MOD);
}

mat stat[50005];
mat v[200005];

void build(int n, int l, int r) {
    if (l > r) return;
    if (l == r) {v[n] = all; return;}
    build(lc(n), l, (l+r)/2);
    build(rc(n), (l+r)/2+1, r);
    v[n] = v[lc(n)] * v[rc(n)];
}

void modify(int n, int l, int r, int lhs, int xx, int yy, int del) {
    if (l > r) return;
    if (l == r) {v[n].a[xx][yy] += del; return;}
    if (lhs <= (l+r)/2) {
        modify(lc(n), l, (l+r)/2, lhs, xx, yy, del);
    } else {
        modify(rc(n), (l+r)/2+1, r, lhs, xx, yy, del);
    }
    v[n] = v[lc(n)] * v[rc(n)];
}

void pmat(mat res) {
    printf("%lld %lld %lld %lld\n", res.a[0][0], res.a[0][1], res.a[1][0], res.a[1][1]);
}

mat query(int n, int l, int r, int lhs, int rhs) {
    if (l > r) return one;
    if (l == r) {return v[n];}
    if (l == lhs && r == rhs) {return v[n];}
    if (rhs <= (l+r) / 2) {
        return query(lc(n), l, (l+r)/2, lhs, rhs);
    } else if (lhs > (l+r)/2) {
        return query(rc(n), (l+r)/2+1, r, lhs, rhs);
    } else {
        return query(lc(n), l, (l+r)/2, lhs, (l+r)/2) * query(rc(n), (l+r)/2+1, r, (l+r)/2+1, rhs);
    }
}

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
                ll tot = 0;
                scanf("%d%d", &l, &r);
                mat res = query(1, 1, n-1, l, r-1);
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        tot = (tot + res.a[i][j]) % MOD;
                    }
                }
                printf("%d\n", tot);
            } else {
                scanf("%d%d%d", &x, &y, &z);
                if (stat[x].a[y-1][z-1]) {
                    stat[x].a[y-1][z-1] = false;
                    modify(1, 1, n-1, x, y-1, z-1, -1);
                } else {
                    stat[x].a[y-1][z-1] = true;
                    modify(1, 1, n-1, x, y-1, z-1, 1);
                }
            }
        }
    }
}
