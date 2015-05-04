//
//  main.cpp
//  cf30C
//
//  Created by eycia on 15/1/4.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

struct node {
    int x, y, t;
    double p;

    inline bool operator<(const node &a) const {
        return t < a.t;
    }
} d[1005];

double f[1005][1005];

inline double distant(int i, int j) {
    return sqrt((d[i].x - d[j].x) * (d[i].x - d[j].x) + (d[i].y - d[j].y) * (d[i].y - d[j].y));
}

double eps = 1e-9;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].x >> d[i].y >> d[i].t >> d[i].p;
    }
    sort(d+1, d+n+1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            f[i][j] = f[i-1][j];
        }
        double max = 0;
        for (int j = 1; j < i; j++) {
            if ((d[i].t - d[j].t) - distant(i, j) >= -eps) {
                if (f[i-1][j] > max) {
                    max = f[i-1][j];
                }
            }
        }
        f[i][i] = max + d[i].p;
    }
    double max = 0;
    for (int i = 1; i <= n; i++) {
        if (f[n][i] > max) {
            max = f[n][i];
        }
    }
    printf("%.10lf\n", max);
}
