//
//  main.cpp
//  bc24.2
//
//  Created by eycia on 14/12/27.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

long long f[105][105];
bool bl[105];

long long c[105][105];

void genc() {
    memset(c, 0, sizeof(c));
    c[1][1] = 1;
    for (int i = 2; i <= 104; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1])% 1000000007;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, te;
    genc();
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> te;
            bl[i] = (te == 1);
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        bl[0] = bl[2];
        bl[n+1] = bl[n-1];
        
        memset(f, 0, sizeof(f));
        for (int i = 0; i < 105; i++) {
            f[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            f[1][i] = 1 - bl[i-1] ^ bl[i+1];
        }
        for (int l = 2; l <= n; l++) {
            for (int s = 1; s <= n-l+1; s++) {
                int e = s + l - 1;
                for (int mi = s; mi <= e; mi++) {
                    f[l][s] = (f[l][s] + (((f[mi-s][s] * f[e-mi][mi+1]) % 1000000007) * c[e-s+1][mi-s+1]) % 1000000007) % 1000000007;
                }
            }
        }
        cout << f[n][1] << endl;
    }
}
