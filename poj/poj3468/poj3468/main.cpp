//
//  main.cpp
//  poj3468
//
//  Created by eycia on 14/10/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
typedef long long ll;
//SEG

#define lc(a) ((a) << 1)
#define rc(a) ((a) << 1 | 1)

ll Sum[300000];
ll Laz[300000];
int ml[300000];
int mr[300000];
int ps[300000];
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
    int n, q;
    char c;
    int v1, v2, v3;
    while (scanf("%d %d", &n, &q) != EOF) {
        int f = (1 << int(log(n+0.0) / log(2.0) + 0.9999999));
        l1 = n;
        l2 = f;
        //build
        for (int i = f; i < f + n; i++) {
            scanf("%I64d", &Sum[i]);
            ps[i] = 1;
        }
        for (int i = f + n; i < f + f; i++) {
            Sum[i] = 0;
            ps[i] = 0;
        }
        for (int i = f - 1; i > 0; i--) {
            update(i);
        }
        for (int i = 0; i < f; i++) {
            ml[i + f] = mr[i + f] = i + 1;
        }
        for (int i = f - 1; i > 0; i--) {
            ml[i] = ml[lc(i)];
            mr[i] = mr[rc(i)];
            ps[i] = ps[lc(i)] + ps[rc(i)];
        }
        
        for (int i = 0; i < q; i++) {
            getchar();
            scanf("%c %d %d", &c, &v1, &v2);
            if (c == 'Q') {
                printf("%I64d\n", sum(1, v1, v2));
            } else {
                scanf("%d", &v3);
                modify(1, v1, v2, v3);
            }
        }
    }
}
