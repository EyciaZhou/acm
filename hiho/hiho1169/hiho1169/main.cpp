//
//  main.cpp
//  tmp01
//
//  Created by eycia on 9/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define lc(a) (a*2)
#define rc(a) (a*2+1)

vector<int> vv[850000];
int a[400000];

void build(int n, int l, int r) {
    if (l > r) return;
    if (l == r) {vv[n].push_back(a[l]); return ;}
    build(lc(n), l, (l+r)/2);
    build(rc(n), (l+r)/2+1, r);
    //update
    int i = 0, j = 0;
    int ll = lc(n), rr = rc(n);
    while (i < vv[ll].size() && j < vv[rr].size()) {
        if (vv[ll][i] < vv[rr][j]) {
            vv[n].push_back(vv[ll][i++]);
        } else {
            vv[n].push_back(vv[rr][j++]);
        }
    }
    while (i < vv[ll].size()) {
        vv[n].push_back(vv[ll][i++]);
    }
    while (j < vv[rr].size()) {
        vv[n].push_back(vv[rr][j++]);
    }
}

int findin(int n, int qq) {
    int p1 = lower_bound(vv[n].begin(), vv[n].end(), qq) - vv[n].begin();
    
    p1 = max(p1 - 1, 0);
    int p2 = min(p1 + 2, (int)vv[n].size()-1);
    
    int ans = 0x7fffffff;
    
    for (int i = p1; i <= p2; i++) {
        if (abs(vv[n][i]-qq) < ans) {
            ans = abs(vv[n][i]-qq);
        }
    }
    return ans;
}

int query(int n, int l, int r, int ll, int rr, int qq) {
    if (l > r) return 0x7fffffff;
    if (l == ll && r == rr) {
        return findin(n, qq);
    }
    if (ll > (l+r)/2) {
        return query(rc(n), (l+r)/2+1, r, ll, rr, qq);
    } else if (rr <= (l+r)/2) {
        return query(lc(n), l, (l+r)/2, ll, rr, qq);
    } else {
        return min(query(lc(n), l, (l+r)/2, ll, (l+r)/2, qq),
                   query(rc(n), (l+r)/2+1, r, (l+r)/2+1, rr, qq));
    }
}

int main(int argc, const char * argv[]) {
    int t, l, r, v;
    int n, q;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        for (int i = 0; i < 850000; i++) {
            vv[i].clear();
        }
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        build(1, 0, n-1);
        printf("Case #%d:\n", ff);
        for (int i = 0; i < q; i++) {
            scanf("%d %d %d", &l, &r, &v);
            printf("%d\n", query(1, 0, n-1, l-1, r-1, v));
        }
    }
}
