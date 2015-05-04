//
//  main.cpp
//  gd2
//
//  Created by eycia on 14/11/9.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

#define lc(a) ((a) << 1)
#define rc(a) ((a) << 1 | 1)

ll Sum[20000];
ll Laz[20000];
int ml[20000];
int mr[20000];
int ps[20000];
int l1, l2;

inline void update(int p) {
    Sum[p] = Sum[lc(p)] + Sum[rc(p)];
}

inline void lazy(int p) {
    if (Laz[p] != 0) {
        Laz[lc(p)] += Laz[p];
        Laz[rc(p)] += Laz[p];
        Sum[lc(p)] += ps[lc(p)] * Laz[p];
        Sum[rc(p)] += ps[rc(p)] * Laz[p];
        Laz[p] = 0;
    }
}

ll sum(int p, int s, int e) {
    if (p >= l2) {
        return Sum[p];
    }
    
    lazy(p);
    
    if (s == ml[p] && e == mr[p]) {
        return Sum[p];
    }
    if (s >= ml[rc(p)]) {
        return sum(rc(p), s, e);
    } else if (e <= mr[lc(p)]) {
        return sum(lc(p), s, e);
    }
    
    return sum(lc(p), s, mr[lc(p)]) + sum(rc(p), ml[rc(p)], e);
}

void modify(int p, int s, int e, int v) {
    if (s == ml[p] && e == mr[p]) {
        Laz[p] += v;
        Sum[p] += v * ps[p];
        return;
    }
    
    lazy(p);
    
    if (s >= ml[rc(p)]) {
        modify(rc(p), s, e, v);
    } else if (e <= mr[lc(p)]) {
        modify(lc(p), s, e, v);
    } else {
        modify(lc(p), s, mr[lc(p)], v);
        modify(rc(p), ml[rc(p)], e, v);
    }
    
    update(p);
}

//END SEG

int main(int argc, const char * argv[]) {
    int ff;
    cin >> ff;
    for (int tt = 1; tt <= ff; tt++) {
        cout << "Case #" << tt << ":";
        memset(Laz, 0, sizeof(Laz));
        int n = 5005;
        int f = (1 << int(log(n+0.0) / log(2.0) + 0.9999999));
        l1 = n;
        l2 = f;
        //cout << l1 << " " << l2 << endl;
        //build
        for (int i = f; i < f + n; i++) {
            Sum[i] = 0;
            ps[i] = 1;
        }
        for (int i = f + n; i < f + f; i++) {
            Sum[i] = 0;
            ps[i] = 0;
        }
        for (int i = 0; i < f; i++) {
            ml[i + f] = mr[i + f] = i + 1;
        }
        for (int i = f - 1; i > 0; i--) {
            ml[i] = ml[lc(i)];
            mr[i] = mr[rc(i)];
            Sum[i] = 0;
            ps[i] = ps[lc(i)] + ps[rc(i)];
        }
        
        int nn, aa, bb;
        cin >> nn;
        for (int i = 0; i < nn; i++) {
            cin >> aa >> bb;
            modify(1, aa, bb, 1);
        }
        cin >> bb;
        for (int i = 0; i < bb; i++) {
            cin >> aa;
            cout << " " << sum(1, aa, aa);
        }
        cout << endl;
    }
}
