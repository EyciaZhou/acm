//
//  main.cpp
//  cf243b
//
//  Created by eycia on 14/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

vector<int> g[100005];
int bs[100005];
int co[100005];
int n, m, h, t;

bool ff(int now) {
    int one=0, two=0, tir=0;
    for (int i = 0; i < g[now].size(); i++) {
        co[g[now][i]] = 2;
        one++;
    }
    one--;
    for (int i = 0; i < g[now].size(); i++) {
        int p = g[now][i];
        if (bs[p]-1 < t) continue;
        tir = 0; two = 0;
        for (int j = 0; j < g[p].size(); j++) {
            
            if (g[p][j] == now) continue;
            if (co[g[p][j]] == 2) {
                co[g[p][j]] = 3;
                tir++;
            } else {
                co[g[p][j]] = 1;
                two++;
            }
        }
        int oo = one - tir;
        if (oo + tir >= h && two + tir >= t && oo+two+tir >= h+t) {
            cout << "YES" << endl;
            cout << now << " " << p << endl;
                int tot = 0;
                for (int j = 0; j < g[now].size(); j++) {
                    i = g[now][j];
                    if (i == now || i == p) continue;
                    if (co[i] == 2) {
                        tot++;
                        if (tot > h) {
                            break;
                        }
                        co[i] = 0;
                        printf("%d ", i);
                    }
                }
                for (int j = 0; j < g[now].size(); j++) {
                    i = g[now][j];
                    if (i == now || i == p) continue;
                    if (co[i] == 3) {
                        tot++;
                        if (tot > h) {
                            break;
                        }
                        co[i] = 0;
                        printf("%d ", i);
                    }
                }
            cout << endl;
            tot = 0;
            for (int j = 0; j < g[p].size(); j++) {
                i = g[p][j];
                if (i == now || i == p) continue;
                if (co[i] == 1) {
                    tot++;
                    if (tot > t) {
                        break;
                    }
                    co[i] = 0;
                    printf("%d ", i);
                }
            }
            for (int j = 0; j < g[p].size(); j++) {
                i = g[p][j];
                if (i == now || i == p) continue;
                if (co[i] == 3) {
                    tot++;
                    if (tot > t) {
                        break;
                    }
                    co[i] = 0;
                    printf("%d ", i);
                }
            }
            return true;
        }
        for (int j = 0; j < g[p].size(); j++) {
            if (g[p][j] == now) continue;
            if (co[g[p][j]] == 3) {
                co[g[p][j]] = 2;
            }
        }
    }
    return false;
}

map<int, int> mm;
vector<pair<int, int> > vs;

int main(int argc, const char * argv[]) {
    int u, v;
    cin >> n >> m;
    cin >> h >> t;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);g[v].push_back(u);
        bs[u]++;bs[v]++;
        mm[u]++;mm[v]++;
    }
    for (map<int, int>::reverse_iterator it = mm.rbegin(); it != mm.rend(); it++) {
        if (bs[it->first] -1 >= h)
        vs.push_back(make_pair(it->second, it->first));
    }
    sort(vs.begin(), vs.end());
    for (vector<pair<int, int> >::reverse_iterator it = vs.rbegin(); it != vs.rend(); it++) {
        memset(co, 0, sizeof(co));
        if (!(bs[it->second]-1 < h) && ff(it->second)) {
            return 0;
        }
    }
    cout << "NO" << endl;
}