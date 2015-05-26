//
//  main.cpp
//  baidu-zige-1004
//
//  Created by eycia on 24/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define eps 1e-8
#define pi acos(-1)

inline double gs(int n, double k) {
    return k / (2 * tan(pi/n));
}

int main(int argc, const char * argv[]) {
    int t, n;
    double k, r;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        printf("Case #%d:\n", ff);
        scanf("%d %lf %lf", &n, &k, &r);
        double lr = gs(n, k);
        if (fabs(r - lr) < eps || lr > r) {
            puts("Give me a kiss!");
        } else {
            puts("I want to kiss you!");
        }
    }
}
