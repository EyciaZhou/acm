//
//  main.cpp
//  bc16.1
//
//  Created by eycia on 14/11/1.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>

int a[450000];

int MOD = 1000000007;

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n;
        long long tot = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            tot = (tot + a[i]) % MOD;
        }
        long long sum = 0;
        for (int i = 0; i <= n / 2; i++) {
            sum += tot * (n - 2 * i) % MOD;
            sum = sum % MOD;
            tot -= a[i];
            tot -= a[n - i - 1];
            while (tot < 0) {
                tot += MOD;
            }
        }
        printf("%lld\n", sum);
    }
}
