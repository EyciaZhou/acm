//
//  main.cpp
//  cf546E
//
//  Created by eycia on 26/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int g[206][206];
int h[206][206];
bool v[206];
int f[206], pri[206];

int a[106], b[106];

#define ll long long
#define INF 0x7fffffff

int st, en;

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
        for (int i = 1; i <= 205; i++) {
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
            h[now][pri[now]] += f;
            h[pri[now]][now] -= f;
            now = pri[now];
        }
    }
    return tot;
}

int main(int argc, const char * argv[]) {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    int tot = 0, t2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        t2 += a[i];
        g[0][i] = a[i];
        g[i][i+100] = INF;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        tot += b[i];
        g[i+100][205] = b[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        g[u][v+100] = g[v][u+100] = INF;
    }
    st = 0;
    en = 205;
    int z = zdl();
    if (z == tot && t2 == tot) {
        puts("YES");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << -h[i][j+100] << " ";
            }
            cout << endl;
        }
    } else {
        puts("NO");
    }
}
