//
//  main.cpp
//  hiho1033
//
//  Created by eycia on 7/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

bool v[20][10][400];
pair<ll, ll> f[20][10][400];

int code[20];
ll ten[20];

#define MOD 1000000007

pair<ll, ll> dfs(int l, int n, int k, bool lim) {
    ll ans = 0;
    ll count = 0;
    if (l == 1) {
        if (n == k) {
            return {k, 1};
        } else {
            return {0, 0};
        }
    }
    if (lim) {
        for (int i = 0; i < code[l-1]; i++) {
            pll tmp = dfs(l-1, i, - k + n, false);
            ans = (ans + tmp.first) % MOD;
            count = (count + tmp.second) % MOD;
        }
        pll tmp = dfs(l-1, code[l-1], - k + n, true);
        ans = (ans + tmp.first) % MOD;
        count = (count + tmp.second) % MOD;
        
        ans = (ans + (count * n) % MOD * ten[l]) % MOD;
    } else {
        if (v[l][n][k+200]) {
            return f[l][n][k+200];
        }
        
        for (int i = 0; i <= 9; i++) {
            pll tmp = dfs(l-1, i, - k + n, false);
            ans = (ans + tmp.first) % MOD;
            count = (count + tmp.second) % MOD;
        }
        ans = (ans + (count * n) % MOD * ten[l]) % MOD;
        
        v[l][n][k+200] = true;
        f[l][n][k+200] = {ans, count};
    }
    return {ans, count};
}

ll find(string target, int k) {
    for (int i = 0; i < target.size(); i++) {
        code[target.size() - i] = target[i] - '0';
    }
    ll ans = 0;
    ans = (ans + dfs(target.size(), code[target.size()], k, true).first) % MOD;
    for (int i = 1; i < code[target.size()]; i++) {
        ans = (ans + dfs(target.size(), i, k, false).first) % MOD;
    }
    for (int i = 1; i < target.size(); i++) {
        for (int j = 1; j <= 9; j++) {
            ans = (ans + dfs(i, j, k, false).first) % MOD;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    ten[1] = 1;
    for (int i = 2; i < 20; i++) {
        ten[i] = (ten[i-1] * 10) % MOD;
    }
    string l, r;
    int k;
    cin >> l >> r >> k;
    ll ans = find(r, k) - find(l, k);
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
}
