//
//  main.cpp
//  cf475D
//
//  Created by eycia on 15/1/9.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int a[100005];

map<int, long long> f[2];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, long long> ans;
    f[0].clear();
    f[1].clear();
    for (int i = 0; i < n; i++) {
        f[i&1].clear();
        f[i&1][a[i]] = 1;
        for (map<int, long long>::iterator it = f[(i+1)&1].begin(); it != f[(i+1)&1].end(); it++) {
            f[i&1][__gcd(it->first, a[i])] += it->second;
        }
        
        for (map<int, long long>::iterator it = f[i&1].begin(); it != f[i&1].end(); it++) {
            ans[it->first] += it->second;
        }
    }
    int q, qq;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> qq;
        cout << ans[qq] << endl;
    }
}
