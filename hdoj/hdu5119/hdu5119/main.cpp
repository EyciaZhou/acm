//
//  main.cpp
//  hdu5119
//
//  Created by eycia on 14/11/30.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>

int f[2][1050000];
int aa[45];

int main(int argc, const char * argv[]) {
    int ff, n, m;
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &aa[i]);
        }
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int k = aa[i];
            int i1 = i % 2;
            int i2 = (i + 1) % 2;
            for (int j = 0; j < 1048576; j++) {
                f[i1][j] = f[i2][j^k] + f[i2][j];
            }
        }
        long long tot = 0;
        for (int i = m; i < 1048576; i++) {
            tot += f[n % 2][i];
        }
        printf("Case #%d: %I64d\n", tt, tot);
    }
}
