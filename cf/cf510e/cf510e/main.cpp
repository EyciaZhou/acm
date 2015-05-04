//
//  main.cpp
//  cf510e
//
//  Created by eycia on 15/2/11.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

#define INF 0x7fffffff
#define ST 0
#define EN (n+1)

int n;
int a[205];

int g[205][205];
int f[205][205];
int pre[205];
bool v[205];
int flow[205];

ostringstream ans;

bool isprime(int k) {
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0) {
            return false;
        }
    }
    return true;
}

int find_one() {
    memset(v, false, sizeof(v));
    queue<int> q;
    q.push(ST);
    v[ST] = true;
    flow[ST] = INF;
    flow[EN] = 0;
    
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int i = 1; i <= n+1; i++) {
            if (g[s][i] > 0 && !v[i]) {
                pre[i] = s;
                flow[i] = min(g[s][i], flow[s]);
                v[i] = true;
                q.push(i);
                if (i == EN) {
                    return flow[EN];
                }
            }
        }
    }
    return flow[EN];
}

int zdl() {
    int tot = 0;
    while (int ll = find_one()) {
        int end = EN;
        while (end != ST) {
            g[end][pre[end]] += ll;
            g[pre[end]][end] -= ll;
            f[end][pre[end]] += ll;
            f[pre[end]][end] -= ll;
            end = pre[end];
        }
        tot += ll;
    }
    return tot;
}

void dfs(int st, int now, int tot) {
    if (tot > 0 && now == st) {
        ans << tot << " " << now << " ";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i] && f[i][now] != 0) {
            if (f[now][i] > 0) {
                f[now][i]--;
                f[i][now]++;
            } else {
                f[now][i]++;
                f[i][now]--;
            }
            dfs(st, i, tot+1);
            ans << now << " ";
            return;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            g[ST][i] = 2;
        } else {
            g[i][EN] = 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i]%2 && !(a[j]%2)) {
                if (isprime(a[i] + a[j])) {
                    g[i][j] = 1;
                }
            }
        }
    }
    if (zdl() != n) {
        cout << "Impossible" << endl;
        return 0;
    }
    
    memset(v, false, sizeof(v));
    int tot = 0;
    for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!v[j] && f[j][i] != 0) {
                    if (f[j][i] > 0) {
                        f[j][i]--;
                        f[i][j]++;
                    } else {
                        f[j][i]++;
                        f[i][j]--;
                    }
                    tot++;
                    dfs(i, j, 1);
                    ans << endl;
                }
            }
    }
    cout << tot << endl;
    cout << ans.str();
}
