//
//  main.cpp
//  bc20.2
//
//  Created by eycia on 14/11/29.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int ps[200010];
int s1[100010];
int s2[100010];
int mes;
int mem;

int pa[1005]; //1000part 100num
int re[1005][305];

inline void insert(int l, int r) {
    int l1 = l / 300;
    int l2 = l % 300;
    int r1 = r / 300;
    int r2 = r % 300;
    if (l1 == r1) {
        for (int i = l2; i <= r2; i++) {
            re[l1][i]++;
        }
    } else {
    for (int i = l1 + 1; i <= r1 - 1; i++) {
        pa[i] ++;
    }
    for (int i = l2; i < 300; i++) {
        re[l1][i] ++;
    }
    for (int i = 0; i <= r2; i++) {
        re[r1][i] ++;
    }
    }
}


int main(int argc, const char * argv[]) {
    //freopen("/Volumes/code/code/acm/bc/bc20.2/bc20.2/i", "r", stdin);
    int ff, n;
    int t1, t2;
    scanf("%d", &ff);
    while (ff--) {
        mem = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &t1, &t2);
            ps[++mem] = t1;
            ps[++mem] = t2;
            s1[i] = t1;
            s2[i] = t2;
        }
        sort(ps, ps+mem+1);
        int j = 0;
        for (int i = 1; i <= mem; i++) {
            if (ps[i] != ps[i-1]) {
                ps[++j] = ps[i];
            }
        }
        mem = j;
        memset(re, 0, sizeof(re));
        memset(pa, 0, sizeof(pa));
        for (int i = 0; i < n; i++) {
            long r1 = lower_bound(ps, ps+mem+1, s1[i]) - ps;
            long r2 = lower_bound(ps, ps+mem+1, s2[i]) - ps;
            insert(r1, r2);
        }
        int ma = -1;
        for (int i = 0; i <= j / 300; i++) {
            for (int j = 0; j < 300; j++) {
                if (re[i][j] + pa[i] > ma) {
                    ma = re[i][j] + pa[i];
                }
            }
        }
        printf("%d\n", ma);
    }
}
