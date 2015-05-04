//
//  main.cpp
//  bczm2aa
//
//  Created by eycia on 25/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <vector>
#include <map>
#include <cstdio>
using namespace std;

vector<int> g[100005];
vector<int> h[100005];
map<int, int> f[100005];
int fa[100005];
int co[100005];

void dfs(int fat, int now) {
    fa[now] = fat;
    for (int i = 0; i < g[now].size(); i++) {
        if (g[now][i] != fat) {
            h[now].push_back(g[now][i]);
        }
    }
    f[now][0] = h[now].size();
    for (int i = 0; i < h[now].size(); i++) {
        dfs(now, h[now][i]);
    }
}

int main(int argc, const char * argv[]) {
    int t, n, q, u, v, o, tr, c;
    int ans;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        printf("Case #%d:\n", ff);
        ans = 1;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            h[i].clear();
            f[i].clear();
            co[i] = 0;
        }
        co[0] = -1;
        for (int i = 0; i < n-1; i++) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, 1);
        scanf("%d", &q);
        while (q--) {
            scanf("%d", &o);
            if (o == 1) {
                printf("%d\n", ans);
            } else {
                scanf("%d %d", &tr, &c);
                
                if (c == co[tr]) continue;
                
                if (c == co[fa[tr]]) {
                    ans--;
                } else if (c != co[fa[tr]] && co[tr] == co[fa[tr]]){
                    ans++;
                }
                
                ans -= h[tr].size() - f[tr][co[tr]];
                ans += h[tr].size() - f[tr][c];
                
                f[fa[tr]][co[tr]]--;
                f[fa[tr]][c]++;
                
                co[tr] = c;
            }
        }
    }
}