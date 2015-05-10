//
//  main.cpp
//  hdu5179
//
//  Created by eycia on 10/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace  std;

vector<ll> ans;

ll ten[10];

void dfs(int c, ll now, int end) {
    if (c > 10) {
        return;
    }
    ans.push_back(now);
    for (int i = 1; i <= 9; i++) {
        if (end * i <= 9) {
            dfs(c+1, now+ten[c]*end*i, end*i);
        }
    }
}

int main(int argc, const char * argv[]) {
    ten[0] = 1;
    for (int i = 1; i < 10; i++) {
        ten[i] = ten[i-1] * 10;
    }
    dfs(0, 0, 1);
    
    sort(ans.begin(), ans.end());
   
    int t;
    ll l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << lower_bound(ans.begin(), ans.end(), r+1) - lower_bound(ans.begin(), ans.end(), l) << endl;
    }
}