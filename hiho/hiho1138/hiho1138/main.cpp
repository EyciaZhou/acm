//
//  main.cpp
//  hiho1138
//
//  Created by eycia on 23/4/15.
//  Copyright (c) 2015 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

vector<pair<pair<ll, ll>, int> > ps;
vector<pair<pair<ll, ll>, int> > qs;

long long ans;
int n;
bool v[100005];
ll d[100005];

queue<int> q;

vector<pair<int, ll> > g[100005];

inline ll dis(pair<ll, ll> &l, pair<ll, ll> &r) {
    return min(abs(l.first - r.first), abs(l.second - r.second));
}

void spfa() {
    while (!q.empty()) q.pop();
    memset(v, false, sizeof(v));
    q.push(0);
    for (int i = 0; i < n+1; i++) {
        d[i] = -1;
    }
    v[0] = true;
    d[0] = 0;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        v[k] = false;
        for (int i = 0; i < g[k].size(); i++) {
            ll di = d[k] + g[k][i].second;
            int np = g[k][i].first;
            if (di < d[np] || d[np] == -1) {
                d[np] = di;
                if (!v[np]) {
                    v[np] = true;
                    q.push(np);
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ll x, y;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            ps.push_back({{x, y}, i});
            qs.push_back({{y, x}, i});
        }
        sort(ps.begin(), ps.end());
        for (int i = 1; i < ps.size(); i++) {
            g[ps[i].second].push_back({ps[i-1].second, dis(ps[i].first, ps[i-1].first)});
            g[ps[i-1].second].push_back({ps[i].second, dis(ps[i].first, ps[i-1].first)});
        }
        
        sort(qs.begin(), qs.end());
        for (int i = 1; i < qs.size(); i++) {
            g[qs[i].second].push_back({qs[i-1].second, dis(qs[i].first, qs[i-1].first)});
            g[qs[i-1].second].push_back({qs[i].second, dis(qs[i].first, qs[i-1].first)});
        }
        
        spfa();
        cout << d[n-1] << endl;
    }
}
