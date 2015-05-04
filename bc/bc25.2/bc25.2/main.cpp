//
//  main.cpp
//  bc25.2
//
//  Created by eycia on 15/1/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

long long f[55][55];

long long c[105][105];

#define MOD 1000000007

void genc() {
    memset(c, 0, sizeof(c));
    c[1][1] = 1;
    for (int i = 2; i <= 104; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }
}

inline long long C(int i, int j) {
    return c[i+1][j+1];
}

long long two[60];

void gentwo() {
    two[0] = 1;
    for (int i = 1; i < 60; i++) {
        two[i] = (two[i-1] * 2) % MOD;
    }
}

int main(int argc, const char * argv[]) {
    genc();
    gentwo();
    int n, m;
    while (cin >> n >> m) {
        memset(f, 0, sizeof(f));
        if (n == 0 || m == 0) {
            cout << 1 << endl;
            continue;
        }
        for (int j = 1; j <= m; j++) {
            f[1][j] = C(m, j);
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int l = 1; l <= j; l++) {
                    int k = j - l;
                    if (k == 0) {
                        f[i][j] = ((f[i][j] + ((f[i-1][l] * C(m-l, k)) % MOD * (two[l] + (MOD-1)) % MOD) % MOD) % MOD) % MOD;
                    }else {
                        f[i][j] = (f[i][j] + ((f[i-1][l] * C(m-l, k)) % MOD * two[l]) % MOD) % MOD;
                    }
                }
            }
        }
        cout << f[n][m] << endl;
    }
}
