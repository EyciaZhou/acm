//
//  main.cpp
//  hdu1081
//
//  Created by eycia on 14-10-16.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int mat[105][105];
int tot[105][105];

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        memset(mat, 0, sizeof(mat));
        memset(tot, 0, sizeof(tot));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mat[i][j];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                tot[i][j] = tot[i - 1][j] + mat[i][j];
            }
        }
        
        int ma = 100*100*(-128);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int t0 = 0;
                for (int k = 1; k <= n; k++) {
                    if (t0 < 0) {
                        t0 = tot[j][k] - tot[i - 1][k];
                    } else {
                        t0 += tot[j][k] - tot[i - 1][k];
                    }
                    if (t0 > ma) {
                        ma = t0;
                    }
                }
            }
        }
        cout << ma << endl;
    }
}
