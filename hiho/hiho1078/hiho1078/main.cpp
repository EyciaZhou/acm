//
//  main.cpp
//  hiho1078
//
//  Created by eycia on 12/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;
#define lc(a) ((a)*2)
#define rc(a) ((a)*2+1)

#define lll long long

lll tr[400005];
lll la[400005];
lll a[400005];
lll co[400005];

void update(int t) {
    tr[t] = tr[lc(t)] + tr[rc(t)];
}

void push_down(int t, bool down) {
    if (la[t] >= 0) {
        if (!down) {
            la[lc(t)] = la[rc(t)] = la[t];
            tr[lc(t)] = co[lc(t)] * la[t];
            tr[rc(t)] = co[rc(t)] * la[t];
        }
        la[t] = -1;
    }
}

void build(int t, int l, int r) {
    if (l > r) return;
    if (r == l) {tr[t] = a[l]; la[t] = -1; co[t] = 1; return;}
    build(lc(t), l, (l+r)/2);
    build(rc(t), (l+r)/2+1, r);

    update(t);
    
    la[t] = -1;
    co[t] = co[lc(t)] + co[rc(t)];
}

void modify(int t, int l, int r, int ll, int rr, int w) {
    if (l > r || ll > rr) return;
    
    push_down(t, l == r);
    
    if (l == ll && r == rr) {
        la[t] = w;
        tr[t] = co[t] * la[t];
        return;
    }
    if (rr <= (l+r)/2) {
        modify(lc(t), l, (l+r)/2, ll, rr, w);
    } else if (ll > (l+r)/2+1) {
        modify(rc(t), (l+r)/2+1, r, ll, rr, w);
    } else {
        modify(lc(t), l, (l+r)/2, ll, (l+r)/2, w);
        modify(rc(t), (l+r)/2+1, r, (l+r)/2+1, rr, w);
    }
    
    update(t);
}

lll query(int t, int l, int r, int ll, int rr) {
    if (l > r || ll > rr) return 0;

    push_down(t, l == r);

    if (l == ll & r == rr) {
        return tr[t];
    }
    lll ans = 0;
    if (rr <= (l+r)/2) {
        ans = query(lc(t), l, (l+r)/2, ll, rr);
    } else if (ll > (l+r)/2) {
        ans = query(rc(t), (l+r)/2+1, r, ll, rr);
    } else {
        ans = query(lc(t), l, (l+r)/2, ll, (l+r)/2) +
        query(rc(t), (l+r)/2+1, r, (l+r)/2+1, rr);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n, q, o, l, r, w;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> o;
        if (o == 1) {
            cin >> l >> r >> w;
            modify(1, 1, n, l, r, w);
        } else {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}