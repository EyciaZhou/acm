//
//  main.cpp
//  bc21.2
//
//  Created by eycia on 14/12/6.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#define MOD 1000000007
//#define di 8

long long jc[(10000000 >> 3) + 100];
long long j2[(10000000 >> 3) + 100];

int main(int argc, const char * argv[]) {
    long long mu = 1;
    long long mu2 = 1;
    jc[0] = 1;
    j2[0] = 1;
    for (int i = 1; i <= 10000005; i++) {
        mu = (mu * i) % MOD;
        mu2 = (mu2 * mu) % MOD;
        if (!(i & 0x7)) {
            jc[i >> 3] = mu;
            j2[i >> 3] = mu2;
        }
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        long long k = j2[n >> 3];
        long long k2 = jc[n >> 3];
        for (int i = ((n >> 3) << 3) + 1; i <= n; i++) {
            k2 = (k2 * i) % MOD;
            k = (k * k2) % MOD;
        }
        printf("%I64d\n", k);
    }
}
