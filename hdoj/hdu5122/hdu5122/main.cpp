//
//  main.cpp
//  hdu5122
//
//  Created by eycia on 14/11/30.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>

int a[1000005];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int tot = 0;
        int ma = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (a[i] < ma) {
                ma = a[i];
            } else {
                tot++;
            }
        }
        printf("Case #%d: %d\n", tt, tot);
    }
}
