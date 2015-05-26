//
//  main.cpp
//  cf545c
//
//  Created by eycia on 26/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long

vector<pair<ll, ll> > t;

struct {
    vector<ll> pos;
    void gen() {
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
    }
    ll fd(ll n) {
        return lower_bound(pos.begin(), pos.end(), n) - pos.begin() + 1;
    }
} lsh;

ll f[300005];

#define yq(i) (lsh.fd(t[i].first+t[i].second))
#define bq(i) (lsh.fd(t[i].first))

inline void gx(ll &lhs, ll &rhs) {
    lhs = max(lhs, rhs);
}

int main(int argc, const char * argv[]) {
    int n, pos, hi;
    cin >> n;
    
    memset(f, 0, sizeof(f));
    t.clear();
    t.push_back({-2000000005, 0});
    lsh.pos.push_back(-2000000005);
    t.push_back({2000000005, 0});
    lsh.pos.push_back(2000000005);
    for (int i = 0; i < n; i++) {
        cin >> pos >> hi;
        t.push_back({pos, hi});
        lsh.pos.push_back(pos);
        lsh.pos.push_back(pos-hi);
        lsh.pos.push_back(pos+hi);
    }
    sort(t.begin(), t.end());
    lsh.gen();
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i].first > t[i-1].first+t[i-1].second) {
            f[bq(i)] = max(f[bq(i)], f[yq(i-1)]);
        }
        if (t[i].first > t[i-1].first) {
            f[bq(i)] = max(f[bq(i)], f[bq(i-1)]);
        }
        
        if (t[i].first-t[i].second > t[i-1].first) {
            f[bq(i)] = max(f[bq(i)], f[bq(i-1)] + 1);
        }
        if (t[i].first-t[i].second > t[i-1].first+t[i-1].second) {
            f[bq(i)] = max(f[bq(i)], f[yq(i-1)] + 1);
        }
        
        if (t[i].first+t[i].second < t[i+1].first) {
            if (t[i].first > t[i-1].first) {
                f[yq(i)] = max(f[yq(i)], f[bq(i-1)] + 1);
            }
            if (t[i].first > t[i-1].first+t[i-1].second) {
                f[yq(i)] = max(f[yq(i)], f[yq(i-1)] + 1);
            }
        }
    }
    ll mx = 0;
    for (int i = 1; i <= lsh.pos.size(); i++) {
        mx = max(mx, f[i]);
    }
    cout << mx << endl;
}