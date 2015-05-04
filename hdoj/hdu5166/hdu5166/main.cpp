//
//  main.cpp
//  bc28a
//
//  Created by eycia on 15/1/31.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool has[1005];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n, k;
        scanf("%d", &n);
        memset(has, false, sizeof(has));
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            has[k] = true;
        }
        int tot = 0;
        k = 1;
        int res[2];
        while (tot < 2) {
            if (!has[k]) {
                res[tot++] = k;
            }
            k++;
        }
        int t;
        if (res[0] > res[1]) {
            t = res[0];
            res[0] = res[1];
            res[1] = t;
        }
        printf("%d %d\n", res[0], res[1]);
    }
}
