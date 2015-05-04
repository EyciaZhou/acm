//
//  main.cpp
//  bc20.1
//
//  Created by eycia on 14/11/29.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstring>
#include <cstdio>

int a[105];

int main(int argc, const char * argv[]) {
    int ff, k, t;
    scanf("%d", &ff);
    while (ff--) {
        memset(a, 0, sizeof(a));
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &t);
            a[t]++;
        }
        int ma = -1;
        int j = 0;
        for (int i = 1; i <= k; i++) {
            if (a[i] > ma) {
                ma = a[i];
                j = i;
            }
        }
        printf("%d\n", j);
    }
}
