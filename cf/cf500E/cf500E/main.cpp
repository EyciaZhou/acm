//
//  main.cpp
//  cf500E
//
//  Created by eycia on 15/1/5.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;

vector<long long> ls;
int lls;
long long pp[200005];
long long ll[200005];

vector<pair<pair<int, int>, int> > qs;
long long ans[200005];

#define lc(a) (a << 1)
#define rc(a) (a << 1 | 1)

bool c[200005 * 8];
long long l[200005 * 8];

inline void update(long long t) {
    l[t] = l[lc(t)] + l[rc(t)];
}

inline void push_down(long long t) {
    if (c[t]) {
        c[t] = false;
        c[lc(t)] = true;
        c[rc(t)] = true;
        l[lc(t)] = 0;
        l[rc(t)] = 0;
    }
}

void build(long long t, int le, int ri) {
    if (le == ri) {
        l[t] = ls[le+1] - ls[le];
        return;
    }
    int mi = (le + ri) / 2;
    build(lc(t), le, mi);
    build(rc(t), mi+1, ri);
    c[t] = false;
    update(t);
    //cout << t << " " << l[t] << endl;
}

void add(long long t, int cl, int cr, int ql, int qr) {
    if (ql < cl || qr > cr) {
        return ;
    }
    if (qr > lls || ql > qr) {
        return ;
    }
    //cout << "add: " << t << " " << cl << " " << cr << " " << ql << " " << qr << endl;
    if (cl != cr) {
        push_down(t);
    }
    if (cl == ql && cr == qr) {
        //cout << "amo: " << t << endl;
        c[t] = true;
        l[t] = 0;
        return;
    }
    int mi = (cl + cr) / 2;
    if (ql > mi) {
        add(rc(t), mi+1, cr, ql, qr);
    } else if (qr <= mi) {
        add(lc(t), cl, mi, ql, qr);
    } else {
        add(lc(t), cl, mi, ql, mi);
        add(rc(t), mi+1, cr, mi+1, qr);
    }
    update(t);
}

long long query(long long t, int cl, int cr, int ql, int qr) {
    if (ql < cl || qr > cr) {
        return 0;
    }
    if (qr > lls || ql > qr || cl > cr) {
        return 0;
    }
    if (cl != cr) {
        push_down(t);
    }
    if ((cl == ql && cr == qr) || (cl == cr)) {
        return l[t];
    }
    int mi = (cl + cr) / 2;
    long long result;
    if (ql > mi) {
        result = query(rc(t), mi+1, cr, ql, qr);
    } else if (qr <= mi) {
        result = query(lc(t), cl, mi, ql, qr);
    } else {
        result = query(lc(t), cl, mi, ql, mi) + query(rc(t), mi+1, cr, mi+1, qr);
    }
    update(t);
    return result;
}

int lb(long long v) {
    return lower_bound(ls.begin(), ls.begin() + lls, v) - ls.begin();
}

int main() {
    //freopen("/Users/eycia/i", "r", stdin);
    int len;
    cin >> n;
    ls.push_back(-1);
    for (int i = 1; i <= n; i++) {
        cin >> pp[i] >> len;
        ll[i] = pp[i] + len;
        ls.push_back(pp[i]);
        ls.push_back(ll[i]);
    }
    sort(ls.begin(), ls.end());
    lls = 1;
    for (int i = 1; i < ls.size(); i++) {
        if (ls[i] != ls[i-1]) {
            ls[lls++] = ls[i];
        }
    }
    lls--;
    build(1, 1, lls);
    
    
    int q, s, t;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s >> t;
        qs.push_back(make_pair(make_pair(s, t), i));
    }
    sort(qs.begin(), qs.end());
    for (int i = qs.size() - 1, j = n; i >= 0; i--) {
        while (j >= 1 && pp[j] >= pp[qs[i].first.first]) {
            add(1, 1, lls, lb(pp[j]), lb(ll[j])-1);
            j--;
        }
        ans[qs[i].second] = query(1, 1, lls, lb(pp[qs[i].first.first]), lb(ll[qs[i].first.second])-1);
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}