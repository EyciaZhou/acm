//
//  main.cpp
//  bc25.1
//
//  Created by eycia on 15/1/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

bool mm[505][505];

int in[505];
bool v[505];


int main(int argc, const char * argv[]) {
    int n, m;
    int u, vi, tot;
    while (cin >> n >> m) {
        memset(mm, false, sizeof(mm));
        memset(in, 0, sizeof(in));
        memset(v, false, sizeof(v));
        tot = 0;
        for (int i = 0; i < m; i++) {
            cin >> u >> vi;
            if (!mm[u][vi]) {
                in[vi]++;
            }
            mm[u][vi] = true;
        }
        while (true) {
            bool chg = false;
            for (int i = 1; i <= n; i++) {
                if (!v[i] && in[i] == 0) {
                    chg = true;
                    v[i] = true;
                    tot++;
                    for (int j = 1; j <= n; j++) {
                        if (mm[i][j]) {
                            in[j]--;
                            mm[i][j] = false;
                        }
                    }
                    break;
                }
            }
            if (!chg) {
                break;
            }
        }
        if (tot!=n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
