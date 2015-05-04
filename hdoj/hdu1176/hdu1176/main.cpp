//
//  main.cpp
//  hdu1176
//
//  Created by eycia on 14/11/14.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>

int ma[110000][13];
int f[110000][13];

int main(int argc, const char * argv[]) {
    int m, p, t;
    while (scanf("%d", &m) != EOF) {
        if (m == 0) {
            break;
        }
        int mt = 0;
        memset(ma, 0, sizeof(ma));
        memset(f, 0, sizeof(f));
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &p, &t);
            ma[t][p+1]++;
            if (t > mt) {
                mt = t;
            }
        }
        for (int i = 0; i <= 5; i++) {
            for (int j = 1; j <= 5 - i; j++) {
                ma[i][j] = 0;
            }
            for (int j = 11; j > 6 + i; j--) {
                ma[i][j] = 0;
            }
        }
        int mx = 0;
        if (ma[0][6] > 0) {
            f[0][6] = ma[0][6];
        }
        for (int i = 1; i <= mt; i++) {
            for (int t = 1; t <= 11; t++) {
                f[i][t] = std::max(std::max(f[i-1][t-1], f[i-1][t]), f[i-1][t+1]) + ma[i][t];
                if (f[i][t] > mx) {
                    mx = f[i][t];
                }
            }
        }
        printf("%d\n", mx);
    }
}
