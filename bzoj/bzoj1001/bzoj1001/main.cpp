//
//  main.cpp
//  bzoj1001
//
//  Created by eycia on 15/2/10.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 0x7fffffff
#define STAR 0
#define END (n*m-1)

#define z(a, b) ((a) * m + (b))
#define mov(s, d) ((s) + sx[(d)] * m + sy[(d)])

int n, m;
int g[1005005][6];
int pre[1005005];
bool v[1005005];
int flow[1005005];

int sx[6] = {0, 1, 1, 0, -1, -1};
int sy[6] = {1, 1, 0, -1, -1, 0};

int find_one() {
    memset(v, false, sizeof(v));
    queue<int> q;
    q.push(STAR);
    flow[STAR] = INF;
    flow[END] = 0;
    v[STAR] = true;
    while (!q.empty()) {
        int s = q.front();
        
        q.pop();
        for (int i = 0; i < 6; i++) {
            int tar = mov(s, i);
            
            if (tar < 0 || tar >= n * m) continue;
            
            if (!v[tar] && g[s][i] > 0) {
                flow[tar] = min(flow[s], g[s][i]);
                v[tar] = true;
                pre[tar] = i;
                q.push(tar);
            }
        }
    }
    return flow[END];
}

int zdl() {
    int tot = 0;
    while (int ll = find_one()) {
        int end = END;
        while (end != STAR) {
            int pr = mov(end, (pre[end] + 3) % 6);
            g[pr][pre[end]] -= ll;
            g[end][(pre[end] + 3) % 6] += ll;
            end = pr;
        }
        tot += ll;
    }
    return tot;
}

int main(int argc, const char * argv[]) {
    int v;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            scanf("%d", &v);
            g[z(i, j)][0] = v;
            g[z(i, j+1)][3] = v;
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &v);
            g[z(i, j)][2] = v;
            g[z(i+1, j)][5] = v;
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            scanf("%d", &v);
            g[z(i, j)][1] = v;
            g[z(i+1, j+1)][4] = v;
        }
    }
    printf("%d\n", zdl());
}
