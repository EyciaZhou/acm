//
//  main.cpp
//  13.B
//
//  Created by eycia on 26/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int ma[15][15];

long long f[4096][505];

int two[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
long long jc[] = {1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800,
    479001600};

int zo(int value)
{
    value = (value & 0x55555555) + ((value >> 1) & 0x55555555);
    value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
    value = (value & 0x0F0F0F0F) + ((value >> 4) & 0x0F0F0F0F);
    value = (value & 0x00FF00FF) + ((value >> 8) & 0x00FF00FF);
    value = (value & 0x0000FFFF) + ((value >> 16) & 0x0000FFFF);
    return value;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> ma[i][j];
            }
        }
        
        vector<int> tt[13];
        for (int i = 0; i < two[n]; i++) {
            tt[zo(i)].push_back(i);
        }
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int jj = 0; jj < tt[i-1].size(); jj++) {
                int j = tt[i-1][jj];
                for (int l = 0; l < n; l++) {
                    if (!(j & (1 << l))) {
                        f[j|(1<<l)][m+1] += f[j][m+1];
                        for (int k = 0; k < m; k++) {
                            if (k+ma[i][l+1] >= m) {
                                f[j | (1 << l)][m+1] += f[j][k];
                            } else {
                                f[j | (1 << l)][k+ma[i][l+1]] += f[j][k];
                            }
                        }
                    }
                }
            }
        }
        
        if (f[two[n]-1][m+1] == 0) {
            cout << "No solution" << endl;
        } else {
            long long t = __gcd(jc[n], f[two[n]-1][m+1]);
            cout << jc[n]/t << "/" << f[two[n]-1][m+1]/t << endl;
        }
    }
}
