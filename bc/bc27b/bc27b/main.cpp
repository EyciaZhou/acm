//
//  main.cpp
//  bc27b
//
//  Created by eycia on 15/1/24.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <cstdio>
#include <cmath>

long long q[100005];
int n;
bool dir;

inline long long abs(long long a) {
    return a < 0 ? -a : a;
}

long long distant(int u, int v) {
    long long ans = 0;
    if (u == 1) {
        dir = false;
    }
    if (u == n) {
        dir = true;
    }
    if (u == v) {
        ans = 0;
    } else {
        if (dir ^ (v > u)) {
            ans = abs(q[v] - q[u]);
        } else {
            if (!dir) {
                ans += q[n] - q[u];
                ans += q[n] - q[v];
            } else {
                ans += q[u];
                ans += q[v];
            }
            dir = !dir;
        }
    }
    if (v == 1) {
        dir = false;
    }
    if (v == n) {
        dir = true;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int ff;
    int l, r;
    scanf("%d", &ff);
    while (ff--) {
        int m;
        scanf("%d %d", &n, &m);
        for (int i = 2; i <= n; i++) {
            scanf("%I64d", &q[i]);
        }
        for (int i = 2; i <= n; i++) {
            q[i] += q[i-1];
        }
        
        for (int i = 1; i <= m; i++) {
            long long tot = 0;
            dir = false;
            scanf("%d %d", &l, &r);
            
            tot += distant((i-1)%n + 1, l);
            tot += distant(l, r);
            
            printf("%I64d\n", tot);
        }
    }
}
