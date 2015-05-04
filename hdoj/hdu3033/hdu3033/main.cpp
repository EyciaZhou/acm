//
//  main.cpp
//  hdu3033
//
//  Created by eycia on 14/10/19.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

struct obj {
    int br;
    int pr, va;
    
    inline bool operator<(const obj& a) const
    {
        return br < a.br;
    }
} os[105];

int f[15][10005];

int main(int argc, const char * argv[]) {
    int n, m, k;
    while (cin >> n >> m >> k) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 10005; j++) {
                f[i][j] = -1;
            }
        }
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> os[i].br >> os[i].pr >> os[i].va;
        }
        sort(os, os+n);
        
        for (int i = 0; i < n; i++) {
            for (int mo = m; mo >= 0; mo--) {
                if (os[i].pr <= mo) {
                    if (f[os[i].br][mo - os[i].pr] >= 0) {
                        if (f[os[i].br][mo - os[i].pr] + os[i].va > f[os[i].br][mo]) {
                            f[os[i].br][mo] = f[os[i].br][mo - os[i].pr] + os[i].va;
                        }
                    }
                    if (f[os[i].br-1][mo - os[i].pr] >= 0) {
                        if (f[os[i].br-1][mo - os[i].pr] + os[i].va > f[os[i].br][mo]) {
                            f[os[i].br][mo] = f[os[i].br-1][mo - os[i].pr] + os[i].va;
                        }
                    }
                }
            }
        }
        
        int res = -1;
        for (int i = 0; i <= m; i++) {
            if (f[k][i] > res) {
                res = f[k][i];
            }
        }
        
        if (res == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << res << endl;
        }
    }
}
