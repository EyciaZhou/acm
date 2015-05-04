//
//  main.cpp
//  hdu1198
//
//  Created by eycia on 14-9-23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int mm[12][4] = {
    {1, 0, 0, 1},
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {0, 1, 1, 0},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 1, 0, 1},
    {1, 0, 1, 1},
    {0, 1, 1, 1},
    {1, 1, 1, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0}};

int fa[360005];
int map[550][550];
int sti[4] = {-1,0,1,0};
int stj[4] = {0,1,0,-1};

inline int getf(int s) {
    if (fa[s] == s) {
        return s;
    }
    int t = s;
    while (fa[t] != t) {
        t = fa[t];
    }
    fa[s] = t;
    while (fa[s] != s) {
        s = fa[s];
        fa[s] = t;
    }
    return t;
}

int main(int argc, const char * argv[]) {
    while (true) {
        int m, n;
        char ch;
        cin >> m >> n;
        if (m == -1 && n == -1) {
            break;
        }
        for (int i = 0; i < 360005; i++) {
            fa[i] = i;
        }
        for (int i = 0; i <= m+1; i++) {
            map[i][0] = 11;
            map[i][n+1] = 11;
        }
        for (int j = 0; j <= n+1; j++) {
            map[0][j] = 11;
            map[m+1][j] = 11;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> ch;
                map[i][j] = ch - 'A';
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < 4; k++) {
                    if (mm[map[i][j]][k] && mm[map[i+sti[k]][j+stj[k]]][(k + 2) % 4]) {
                        fa[getf(i * 550 + j)] = getf((i+sti[k]) * 550 + j+stj[k]);
                    }
                }
            }
        }
        int tot = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                getf(i * 550 + j);
                if (fa[i * 550 + j] == i * 550 + j) {
                    tot += 1;
                }
            }
        }
        cout << tot << endl;
    }
}
