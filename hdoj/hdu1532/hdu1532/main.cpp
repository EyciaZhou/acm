//
//  main.cpp
//  hdu1532
//
//  Created by eycia on 10/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define pb push_back
#define ll long long

ll g[205][205];

int st, en, n;

bool v[205];
ll f[205];
int pri[205];

#define INF 0x7fffffff

ll find_one() {
    f[st] = INF;
    f[en] = 0;
    memset(v, false, sizeof(v));
    v[st] = true;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (int i = 1; i <= n+1; i++) {
            if (g[k][i] > 0 && !v[i]) {
                pri[i] = k;
                f[i] = min(g[k][i], f[k]);
                v[i] = true;
                q.push(i);
                if (i == en) {
                    return f[i];
                }
            }
        }
    }
    return f[en];
}

ll zdl() {
    int tot = 0;
    while (ll f = find_one()) {
        //cout << f << endl;
        tot += f;
        int now = en;
        while (now != st) {
            g[now][pri[now]] += f;
            g[pri[now]][now] -= f;
            now = pri[now];
        }
    }
    return tot;
}

int main(int argc, const char * argv[]) {
    int m;
    int u, v, w;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(g, 0, sizeof(g));
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] += w;
            //g[v][u] += w;
        }
        st = 1;
        en = m;
        printf("%d\n", zdl());
    }
}
