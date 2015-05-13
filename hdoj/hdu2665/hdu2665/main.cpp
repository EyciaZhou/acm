//
//  main.cpp
//  hdu2665
//
//  Created by eycia on 12/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define lc (t*2)
#define rc (t*2+1)

int a[100005];
int n;
vector<int> tr[400005];

void build(int t, int l, int r) {
    if (l > r) {return;}
    if (l == r) {tr[t].clear();tr[t].push_back(a[l]); return;};
    int mid = (l+r)/2;
    int ll = lc, rr = rc;
    build(ll, l, mid);
    build(rr, mid+1, r);
    tr[t].resize(tr[ll].size() + tr[rr].size());
    merge(tr[ll].begin(), tr[ll].end(), tr[rr].begin(), tr[rr].end(), tr[t].begin());
}

int query(int t, int l, int r, int ll, int rr, int n) {
    if (l > r || ll > rr) {return 0;}
    if (ll == l && rr == r) {
        return upper_bound(tr[t].begin(), tr[t].end(), n) - tr[t].begin();
    }
    int mid = (l+r)/2;
    if (rr <= mid) {
        return query(lc, l, mid, ll, rr, n);
    } else if (ll > mid) {
        return query(rc, mid+1, r, ll, rr, n);
    } else {
        return query(lc, l, mid, ll, mid, n) + query(rc, mid+1, r, mid+1, rr, n);
    }
}

int bs(int l, int h, int ll, int rr, int v) {
    int m;
    while ( l < h ){
        m = ( l + h ) >> 1; if (query(1, 1, n, ll, rr, m) < v)l=m+1;else h=m;
    }
    return l;
}

int main(int argc, const char * argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int q;
        int l, r, k;
        int mi = 0x7fffffff;
        int ma = -0x7ffffffe;
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ma = max(ma, a[i]);mi = min(mi, a[i]);
        }
        build(1, 1, n);
        while (q--) {
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", bs(mi, ma, l, r, k));
        }
    }
}