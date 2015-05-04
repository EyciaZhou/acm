//
//  main.cpp
//  锁屏
//
//  Created by eycia on 14-9-16.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

long long tot;
int ml = 9;
bool v[10] = {false};

int cc[16][3] = {
    {1, 3, 2},
    {1, 7, 4},
    {1, 9, 5},
    {2, 8, 5},
    {3, 1, 2},
    {3, 7, 5},
    {3, 9, 6},
    {4, 6, 5},
    {6, 4, 5},
    {7, 1, 4},
    {7, 3, 5},
    {7, 9, 8},
    {8, 2, 5},
    {9, 1, 5},
    {9, 3, 6},
    {9, 7, 8}};

bool check(int a, int b) {
    for (int i = 0; i < 16; i++) {
        if (a == cc[i][0] && b == cc[i][1] && !v[cc[i][2]]) {
            return false;
        }
    }
    return true;
}

void tt(long nn, int ll) {
    if (ll == ml) {
        tot++;
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (v[i]) continue;
        if (check(nn % 10, i)) {
            v[i] = true;
            tt(nn * 10 + i, ll + 1);
            v[i] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    tot = 0;
    tt(0, 0);
    printf("%lld\n", tot);
}