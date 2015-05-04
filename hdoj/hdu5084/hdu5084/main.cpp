//
//  main.cpp
//  hdu5084
//
//  Created by eycia on 14/11/27.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int a[2005];

int matrix[1005][1005];

int main(int argc, const char * argv[]) {
    int n, m;
    int ff = 1;
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < 2 * n - 1; i++) {
            scanf("%d", &a[i]);
        }
        int tot;
        for (int i = 0; i < n; i++) {
            tot = 0;
            for (int j = 0; j < n; j++) {
                tot += a[j] * a[n - 1 + i - j];
            }
            for (int j = 0; j <= i; j++) {
                matrix[n - i + j - 1][j] = tot;
                if (j != i) {
                    tot += a[n+j] * a[i - j - 1];
                    tot -= a[j] * a[n - 1 + i - j];
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            tot = 0;
            for (int j = 0; j < n; j++) {
                tot += a[i + j] * a[2 * n - 2 - j];
            }
            for (int j = 0; j < n - i; j++) {
                matrix[j][i+j] = tot;
                if (j != n-i-1) {
                    tot += a[i + j + n] * a[n - 2 - j];
                    tot -= a[i + j] * a[2 * n - 2 - j];
                }
            }
        }
        scanf("%d", &m);
        int ans = 0, r, c;
        long long to = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &r, &c);
            ans = matrix[(r + ans)%n][(c + ans)%n];
            to += ans;
        }
        printf("%I64d\n", to);
    }
}
