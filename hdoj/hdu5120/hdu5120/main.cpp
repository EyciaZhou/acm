//
//  main.cpp
//  hdu5120
//
//  Created by eycia on 14/11/30.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cmath>

int x1, x2, yy1, y2;

double PI = acos(-1);

inline double cal1(int r1, int r2) {
    double d = sqrt((x1 - x2) * (x1 - x2) + (yy1 - y2) * (yy1 - y2));
    if (r1 == 0 || r2 == 0) {
        return 0;
    }
    if (r1 + r2 <= d) {
        return 0;
    }
    int r1u = r1 * r1;
    int r2u = r2 * r2;
    if (r2 >= d + r1) {
        return PI * r1u;
    }
    if (r1 >= d + r2) {
        return PI * r2u;
    }
    double a1 = fabs(acos((r1u + d*d - r2u) / (2.0 * r1 * d)));
    double a2 = fabs(acos((r2u + d*d - r1u) / (2.0 * r2 * d)));
    double s1 = (a1 - 0.5 * sin(2 * a1)) * r1u + (a2 - 0.5 * sin(2 * a2)) * r2u;
    //double s2 = cos(a1) * r1 * cos(PI / 2 - a1) * r1 + cos(a2) * r2 * cos(PI / 2 - a2) * r2;
    return s1;
}

int main(int argc, const char * argv[]) {
    int ff;
    int r1, r2;
    freopen("/Volumes/code/code/acm/hdoj/hdu5120/hdu5120/i", "r", stdin);
    freopen("/Volumes/code/code/acm/hdoj/hdu5120/hdu5120/o", "w", stdout);
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        scanf("%d %d", &r1, &r2);
        scanf("%d %d", &x1, &yy1);
        scanf("%d %d", &x2, &y2);
        if (x1 == x2 && yy1 == y2) {
            printf("Case #%d: %0.6lf\n", tt, PI * r2 * r2 - PI * r1 * r1);
            continue;
        }
        double sum = cal1(r1, r1) - cal1(r1, r2) - cal1(r2, r1) + cal1(r2, r2);
        printf("Case #%d: %0.6lf\n", tt, sum);
    }
}
