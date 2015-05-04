//
//  main.cpp
//  cf508a
//
//  Created by eycia on 15/1/28.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool tab[1005][1005];

bool iis(int x, int y) {
    if (tab[x][y] && tab[x+1][y] && tab[x][y+1] && tab[x+1][y+1]) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int n, m, k, x, y;
    memset(tab, false, sizeof(tab));
    scanf("%d %d %d", &n, &m, &k);
    int step = 0;
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &x, &y);
        tab[x][y] = true;
        if (iis(x-1,y-1) || iis(x-1,y) || iis(x,y-1) || iis(x,y)) {
            step = i;
            break;
        }
    }
    printf("%d\n", step);
}
