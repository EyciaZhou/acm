//
//  main.cpp
//  hdu5135
//
//  Created by eycia on 14/12/24.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int ss[15];
bool use[15];

double area(int i, int j, int k) {
    double p = (ss[i] + ss[j] + ss[k]) / 2.0;
    return sqrt(p * (p - ss[i]) * (p - ss[j]) * (p - ss[k]));
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> ss[i+1];
        }
        memset(use, false, sizeof(use));
        double tot = 0;
        for (int ff = 0; ff < n; ff++) {
            int x = 0, y = 0, z = 0;
            double max = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= n; k++) {
                        if (!use[i] && !use[j] && !use[k]) {
                            if (i != j && i != k && j != k) {
                                if (ss[i] + ss[j] > ss[k] &&
                                    ss[i] + ss[k] > ss[j] &&
                                    ss[j] + ss[k] > ss[i]) {
                                    if (area(i, j, k) > max) {
                                        max = area(i, j, k);
                                        x = i;
                                        y = j;
                                        z = k;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            tot += max;
            use[x] = use[y] = use[z] = true;
        }
        printf("%.2lf\n", tot);
    }
}
