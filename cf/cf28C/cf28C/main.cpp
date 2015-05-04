//
//  main.cpp
//  cf28C
//
//  Created by eycia on 15/1/1.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;

double f[60][60][60];

int a[55];

double c[105][105];

void genc() {
    memset(c, 0, sizeof(c));
    c[1][1] = 1;
    for (int i = 2; i <= 104; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]);
        }
    }
}

inline double C(int i, int j) {
    return c[i+1][j+1];
}

int main(int argc, const char * argv[]) {
    genc();
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++) {
            scanf("%d", &a[i]);
        }
        
        for (int j = 0; j <= m; j++) {
            f[0][j][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int l = 0; l < 55; l++) {
                    f[i][j][l] = 0;
                    for (int kk = 0; kk < a[j]; kk++) {
                        for (int k = 0; k <= l; k++) {
                            int ps = l * a[j] - kk;
                            if (ps > i || ps < 0) continue;
                            f[i][j][l] += f[i-ps][j-1][k] * C(n-i+ps, ps);
                        }
                        for (int k = 0; k < l; k++) {
                            int ps = k * a[j] - kk;
                            if (ps > i || ps < 0) continue;
                            f[i][j][l] += f[i-ps][j-1][l] * C(n-i+ps, ps);
                        }
                    }
                }
            }
        }
        double t2 = 1;
    
        for (int i = 0; i < n; i++) {
            t2 *= m;
        }
    
        double tot = 0;
        for (int i = 0; i < 55; i++) {
            tot += i * f[n][m][i];
        }
        
        cout << fixed <<  setprecision(15) << tot/t2 << endl;
    }
}
