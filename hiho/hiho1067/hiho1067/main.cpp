//
//  main.cpp
//  hiho1067
//
//  Created by eycia on 6/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> g[100005];
vector<pair<int, int> > qu[100005];

int ans[100005];
int ii[100005];
int co[100005];
int fa[100005];

struct {
    map<string, int> ha;
    map<int, string> rha;
    int tot = 1;
    int hsh(string s) {
        if (ha.count(s) != 0) {
            return ha[s];
        }
        rha[tot] = s;
        ha[s] = tot++;
        //cout << s << tot << endl;
        return ha[s];
    }
    string rh(int i) {
        return rha[i];
    }
    void clear() {
        tot = 0;
        ha.clear();
    }
} hsh;

int getf(int now) {
    return fa[now] == now ? now : getf(fa[now]);
}

void dfs(int now) {
    co[now] = 1;
    for (int i = 0; i < qu[now].size(); i++) {
        if (co[qu[now][i].first] != 0) {
            if (co[qu[now][i].first] == 1) {
                ans[qu[now][i].second] = qu[now][i].first;
            }
            if (co[qu[now][i].first] == 2) {
                ans[qu[now][i].second] = getf(qu[now][i].first);
            }
        }
    }
    for (int i = 0; i < g[now].size(); i++) {
        dfs(g[now][i]);
        fa[getf(g[now][i])] = getf(now);
    }
    co[now] = 2;
}

int main(int argc, const char * argv[]) {
    int n, q;
    cin >> n;
    string sfa, sson;
    char s1[105], s2[105];
    int fath, son;
    hsh.clear();
    for (int i = 0; i < 100005; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s%s", s1, s2);
        sfa = string(s1);
        sson = string(s2);
        fath = hsh.hsh(sfa);
        son = hsh.hsh(sson);
        g[fath].push_back(son);
        ii[son]++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%s%s", s1, s2);
        sfa = string(s1);
        sson = string(s2);
        fath = hsh.hsh(sfa);
        son = hsh.hsh(sson);
        qu[fath].push_back({son, i});
        qu[son].push_back({fath, i});
    }
    for (int i = 0; i < hsh.tot; i++) {
        if (ii[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%s\n", hsh.rh(ans[i]).c_str());
    }
}
