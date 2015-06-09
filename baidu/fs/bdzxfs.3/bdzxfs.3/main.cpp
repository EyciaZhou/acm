//
//  main.cpp
//  bdzxfs.3
//
//  Created by eycia on 6/6/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

string ans;

string d[55][30];
bool v[55];
queue<int> q;

int a, b, n;

vector<pair<int, string> > g[55];

inline bool les(string l, string r) {
    cout << l << " " << r << endl;
    if (l.size() == 0) {
        return false;
    }
    if (r.size() == 0) {
        return true;
    }
    int sl = min(l.size(), r.size());
    for (int i = 0; i < sl; i++) {
        if (l[i] < r[i]) {
            return true;
        } else if (l[i] > r[i]) {
            return false;
        }
    }
    return l.size() < r.size();
}

void spfa() {
    while (!q.empty()) q.pop();
    memset(v, false, sizeof(v));
    q.push(a);
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j < 26; j++ ){
            d[i][j] = "}";
        }
    }
    v[a] = true;
    for (int i = 0; i < 26; i++) {
        d[a][i] = "";
    }
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        v[k] = false;
        for (int i = 0; i < g[k].size(); i++) {
            for (int dd = 0; dd < 26; dd++) {
                if(d[k][dd] == "}") continue;
                string di = d[k][dd] + g[k][i].second;
                int np = g[k][i].first;
                if (les(di, d[np][di[di.size()-1]])) {
                    d[np][di[di.size()-1]] = di;
                    if (!v[np]) {
                        v[np] = true;
                        q.push(np);
                    }
                }
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << d[b][i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    int t, u, v, m;
    char tmp[30];
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        for (int i = 0; i < 55; i++)
            g[i].clear();
        scanf("%d %d %d %d", &n, &m, &a, &b);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %s", &u, &v, tmp);
            g[u].push_back(make_pair(v, tmp));
        }
        spfa();
        puts(ans.c_str());
    }
}
