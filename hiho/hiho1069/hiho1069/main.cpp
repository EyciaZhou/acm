//
//  main.cpp
//  hiho1069
//
//  Created by eycia on 7/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct {
    map<string, int> ha;
    map<int, string> rha;
    int tot = 1;
    int h(string s) {
        if (ha.count(s) != 0) {
            return ha[s];
        }
        rha[tot] = s;
        ha[s] = tot++;
        return ha[s];
    }
    string rh(int i) {
        return rha[i];
    }
    void clear() {
        tot = 0;
        ha.clear();
    }
} h;

struct {
    vector<vector<int> > k;
    vector<int> aa;
    void init(vector<int > a) {
        aa = a;
        int mn = a.size();
        int ml = (int)(log(mn) / log(2) + 5);
        for (int i = 0; i < ml; i++) {
            k.push_back(vector<int>());
        }
        for (int i = 0; i < mn; i++) {
            k[0].push_back(i);
        }
        for (int j = 1; j < ml; j++) {
            for (int i = 0; i < mn; i++) {
                if ((1 << (j-1))+i < mn) {
                    if (a[k[j-1][i]] < a[k[j-1][(1 << (j-1))+i]]) {
                        k[j].push_back(k[j-1][i]);
                    } else {
                        k[j].push_back(k[j-1][(1 << (j-1))+i]);
                    }
                } else {
                    k[j].push_back(k[j-1][i]);
                }
            }
        }
    }
    
    int query(int l, int r) {
        if (l > r) swap(r, l);
        int len = r - l + 1;
        int c = int(log(len) / log(2));
        if (aa[k[c][l]] < aa[k[c][r-(1<<c)+1]]) {
            return k[c][l];
        }
        return k[c][r-(1<<c)+1];
    }
} rmq_st;

vector<int> g[100005];
vector<int > raw_v;
vector<int > raw_i;
int ii[100005];

void dfs(int now, int c) {
    raw_v.push_back(now);
    raw_i.push_back(c);
    for (int i = 0; i < g[now].size(); i++) {
        dfs(g[now][i], c+1);
        raw_v.push_back(now);
        raw_i.push_back(c);
    }
}

int lpos[200005];

void gen_lpos() {
    for (int i = 0; i < raw_v.size(); i++) {
        lpos[raw_v[i]] = i;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    char st1[105], st2[105];
    string sfa, sson;
    h.clear();
    for (int i = 0; i < n; i++) {
        scanf("%s %s", st1, st2);
        sfa = string(st1);
        sson = string(st2);
        int fath = h.h(sfa), son = h.h(sson);
        g[fath].push_back(son);
        ii[son]++;
    }
    for (int i = 0; i < h.tot; i++) {
        if (ii[i] == 0) {
            dfs(i, 0);
        }
    }
    rmq_st.init(raw_i);
    gen_lpos();
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        scanf("%s %s", st1, st2);
        sfa = string(st1);
        sson = string(st2);
        int fath = h.h(sfa), son = h.h(sson);
        cout << h.rh(raw_v[rmq_st.query(lpos[fath], lpos[son])]) << endl;
    }
}
