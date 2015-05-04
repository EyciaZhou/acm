//
//  main.cpp
//  hdu5064
//
//  Created by eycia on 14-10-16.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[4200000];
int c[4200000];
int f[3000][3000];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n, m;
        memset(f, 0, sizeof(f));
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        c[0] = a[0];
        int mm = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i-1]) {
                c[mm++] = a[i];
            }
        }
        int st = 0, mn = 0;
        int ma = -1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i-1]) {
                if (i-st > ma) {
                    ma = i-st;
                }
                f[mn][mn] = i - st;
                st = i;
                mn++;
            }
        }
        f[mn][mn] = n - st;
        if (n-st > ma) {
            ma = n-st;
        }
        for (int i = 0; i < mm - 1; i++) {
            int k = i;
            int max = 0;
            for (int j = i + 1; j < mm; j++) {
                for (; k >= 0; k--) {
                    if (c[j] - c[i] >= c[i] - c[k]) {
                        if (f[k][i] > max) {
                            max = f[k][i];
                        }
                    } else {
                        break;
                    }
                }
                f[i][j] = max + 1;
                if (f[i][j] > ma) {
                    ma = f[i][j];
                }
            }
        }
        printf("%d\n", ma);
    }
}
