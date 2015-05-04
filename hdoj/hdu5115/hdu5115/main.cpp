//
//  main.cpp
//  hdu5115
//
//  Created by eycia on 14/11/30.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>

int a[205], b[205];
int f[205][205];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
        }
        a[0] = a[n+1] = b[0] = b[n+1] = 0;
        
        for (int s = 1; s <= n; s++) {
            f[1][s] = a[s] + b[s-1] + b[s+1];
        }
        
        for (int l = 2; l <= n; l++) {
            for (int s = 1; s <= n - l + 1; s++) {
                int e = s + l - 1;
                int ma = 0x7fffffff;
                for (int l2 = 0; l2 <= l - 1; l2++) {
                    if (f[l2][s] + f[l - l2 - 1][s + l2 + 1] + a[s+l2] < ma) {
                        ma = f[l2][s] + f[l - l2 - 1][s + l2 + 1] + a[s+l2];
                    }
                }
                f[l][s] = ma + b[s-1] + b[e+1];
            }
        }
        
        printf("Case #%d: %d\n", tt, f[n][1]);
    }
}
