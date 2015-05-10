//
//  main.cpp
//  hdu1325
//
//  Created by eycia on 10/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

int ii[1000005];
bool v[1000005];

int main(int argc, const char * argv[]) {
    int a, b;
    int ff = 1;
    while (scanf("%d %d", &a, &b) != EOF) {
        if (a == 0 && b == 0) {
            int zero = 0;
            bool flag = false;
            for (int i = 0; i < 1000005; i++) {
                if (v[i]) {
                    if (ii[i] == 0) {
                        zero++;
                        if (zero > 1) break;
                    }
                    if (ii[i] != 1 && ii[i] != 0) {
                        flag = true;
                        break;
                    }
                }
            }
            if (zero != 1 || flag) {
                printf("Case %d is not a tree.\n", ff);
            } else {
                printf("Case %d is a tree.\n", ff);
            }
            memset(ii, 0, sizeof(ii));
            memset(v, false, sizeof(v));
            ff++;
            continue;
        }
        if (a < 0 && b < 0) {
            return 0;
        }
        v[a] = v[b] = true;
        ii[b]++;
    }
}
