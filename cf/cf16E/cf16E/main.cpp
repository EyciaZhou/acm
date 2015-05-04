//
//  main.cpp
//  cf16E
//
//  Created by eycia on 14/12/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

double pro[20][20];

double f[530000];

int has_one(int value)
{
    value = (value & 0x55555555) + ((value >> 1) & 0x55555555);
    value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
    value = (value & 0x0F0F0F0F) + ((value >> 4) & 0x0F0F0F0F);
    value = (value & 0x00FF00FF) + ((value >> 8) & 0x00FF00FF);
    value = (value & 0x0000FFFF) + ((value >> 16) & 0x0000FFFF);
    return value;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pro[i][j];
        }
    }
    f[(1<<n) - 1] = 1;
    for (int ps = n; ps >= 1; ps--) {
        for (int i = 0; i < (1<<n); i++) {
            if (has_one(i) == ps) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if ( k != l && ((i & (1 << k)) > 0) && ((i & (1 << l)) > 0) ) {
                            f[i ^ (1 << k)] += f[i] * pro[l][k] / (ps-1) / (ps);
                            f[i ^ (1 << l)] += f[i] * pro[k][l] / (ps-1) / (ps);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%.6lf ", f[1 << i]);
    }
    printf("\n");
}
