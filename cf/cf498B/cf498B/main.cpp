//
//  main.cpp
//  cf498B
//
//  Created by eycia on 15/1/8.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double f[5005][5005];
double p[5005];
int pt[5005];

int main(int argc, const char * argv[]) {
    int n, t;
    cin >> n >> t;
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> pt[i];
        p[i] /= 100;
    }
    for (int i = 0; i <= t; i++) {
        f[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        double tot = 0;
        for (int j = 1; j < pt[i]; j++) {
            tot = (tot * (1-p[i])) + f[i-1][j-1] * p[i];
            f[i][j] = tot;
        }
        for (int j = pt[i]; j <= t; j++) {
            tot -= f[i-1][j-pt[i]-1] * pow(1-p[i], pt[i]-1);
            tot = (tot * (1-p[i])) + f[i-1][j-1] * p[i];
            tot += f[i-1][j-pt[i]] * pow(1-p[i], pt[i]);
            f[i][j] = tot;
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[i][t];
    }
    printf("%.10lf\n", ans);
}
