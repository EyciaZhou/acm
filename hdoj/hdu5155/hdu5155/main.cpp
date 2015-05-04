//
//  main.cpp
//  bc25.2
//
//  Created by eycia on 15/1/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>

long long f[55][55];
long long c[55][55];

#define MOD 1000000007

void genc() {
    memset(c, 0, sizeof(c));
    c[1][1] = 1;
    for (int i = 2; i <= 54; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }
    for (int i = 1; i <= 54; i++) {
        for(int j = 1; j <= i; j++) {
            c[i-1][j-1] = c[i][j];
        }
    }
}

long long two[60];
long long twom1[60];

void gentwo() {
    two[0] = 1;
    for (int i = 1; i < 60; i++) {
        two[i] = (two[i-1] * 2) % MOD;
        twom1[i] = (two[i] + MOD - 1) % MOD;
    }
}

int main(int argc, const char * argv[]) {
    genc();
    gentwo();
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 || m == 0) {
            printf("1\n");
            continue;
        }
        for (int j = 1; j <= m; j++) {
            f[1][j] = c[m][j];
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                long long ans = 0;
                for (int l = 1; l <= j; l++) {
                    int k = j - l;
                    if (k == 0) {
                        ans = (ans + ((f[i-1][l] * c[m-l][k]) % MOD * twom1[l]) % MOD) % MOD;
                    }else {
                        ans = (ans + ((f[i-1][l] * c[m-l][k]) % MOD * two[l]) % MOD) % MOD;
                    }
                }
                f[i][j] = ans;
            }
        }
        printf("%I64d\n", f[n][m]);
    }
}
