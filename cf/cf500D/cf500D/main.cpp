//
//  main.cpp
//  cf500D
//
//  Created by eycia on 15/1/4.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int a[100005], b[100005], l[100005];
long double ll[100005];
long double rs[100005];

vector<int> g[100005];

long double dfs(int pr, int now) {
    long double tot = 0;
    for (int i = 0; i < g[now].size(); i++) {
        if (g[now][i] != pr) {
            tot+=dfs(now, g[now][i]);
        }
    }
    ll[now] = tot+1;
    return tot+1;
}

int main(int argc, const char * argv[]) {
    long long n;
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        cin >> a[i] >> b[i] >> l[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    dfs(0, 1);
    
    long double fm = n * (n-1) / 2;
    
    for (int i = 1; i <= n-1; i++) {
        long double v1 = ll[a[i]];
        long double v2 = ll[b[i]];
        if (v1 < v2) {
            swap(v1, v2);
        }
        rs[i] = v2 / fm * (ll[1] - v2) ;
    }
    
    long double tt = 0;
    for (int i = 1; i <= n-1; i++) {
        tt += rs[i] * l[i];
    }
    int q;
    int a, b;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        tt -= rs[a] * (l[a] - b);
        l[a] = b;
        cout << fixed << setprecision(10) << tt * 3 << endl;
    }
}
