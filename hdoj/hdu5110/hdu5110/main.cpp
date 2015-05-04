//
//  main.cpp
//  hdu5110
//
//  Created by eycia on 14/11/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int f[36][1005][1005];
int d[1005][1005];
int n, m;

inline void init() {
    int sq = sqrt(n+0.0) + 1;
    for (int k = 1; k <= sq; k++) {
        for (int i = 1; i <= n; i++) {
            if (i-k <= 0) {
                for (int j = 1; j <= m; j++) {
                    f[k][i][j] = d[i][j] - d[i][j-1];
                }
                continue;
            }
            if (i-2*k > 0) {
                for (int j = 1; j <= k; j++) {
                    if (j+k <= m) {
                        f[k][i][j] = f[k][i-k][j+k] + d[i-k][j+k-1] + d[i-2*k][j-1];
                    } else {
                        f[k][i][j] = d[i-k][m] + d[i-2*k][m] + f[k][i-2*k][j] - d[i-2*k][j] + d[i-2*k][j-1];
                    }
                    f[k][i][j] += d[i][j] - d[i][j-1];
                }
                for (int j = k+1; j <= m; j++) {
                    if (j+k <= m) {
                        f[k][i][j] = f[k][i-k][j-k] + f[k][i-k][j+k] - f[k][i-2*k][j] - d[i-k][j-k] + d[i-k][j+k-1];
                    } else {
                        f[k][i][j] = f[k][i-k][j-k] + d[i-k][m] - d[i-k][j-k] + d[i-2*k][m] - d[i-2*k][j];
                    }
                    f[k][i][j] += d[i][j] - d[i][j-1];
                }
            } else {
                for (int j = 1; j <= k; j++) {
                    if (j+k <= m) {
                        f[k][i][j] = f[k][i-k][j+k] + d[i-k][j+k-1];
                    } else {
                        f[k][i][j] = d[i-k][m];
                    }
                    f[k][i][j] += d[i][j] - d[i][j-1];
                }
                for (int j = k+1; j <= m; j++) {
                    if (j+k <= m) {
                        f[k][i][j] = f[k][i-k][j-k] + f[k][i-k][j+k] - d[i-k][j-k] + d[i-k][j+k-1];
                    } else {
                        f[k][i][j] = f[k][i-k][j-k] + d[i-k][m] - d[i-k][j-k];
                    }
                    f[k][i][j] += d[i][j] - d[i][j-1];
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int q;
    int x, y, dd;
    char line[1005];
    while (scanf("%d %d %d", &n, &m, &q) != EOF) {
        getchar();
        for (int i = 1; i <= n; i++) {
            gets(line);
            d[i][0] = 0;
            for (int j = 1; j <= m; j++) {
                d[i][j] = d[i][j-1] + (line[j-1] == 'X');
            }
        }
        init();
        for (int i = 0; i < q; i++) {
            scanf("%d %d %d", &x, &y, &dd);
            if (dd <= sqrt(n+0.0)) {
                printf("%d\n", f[dd][x][y]);
            } else {
                int res = 0;
                for (int i = 0; x - i * dd > 0; i++) {
                    res = res - d[x - i * dd][max(y - i * dd - 1, 0)] + d[x - i * dd][min(y + i * dd, m)];
                }
                printf("%d\n", res);
            }
        }
    }
}
