//
//  main.cpp
//  hdu2089-numdp
//
//  Created by eycia on 14-10-10.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

long long f[25][10];

int main(int argc, const char * argv[]) {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int l = 1; l <= 20; l++) {
        for (int n = 0; n < 10; n++) {
            if (n == 4) continue;
            for (int n2 = 0; n2 < 10; n2++) {
                if (n == 6 && n2 == 2) continue;
                f[l][n] += f[l-1][n2];
            }
        }
    }
    while (true) {
        int n, m;
        cin >> n;
        long long ans = 0;
        int p = 1;
        while (n > 0) {
            for (int i = 0; i < n % 10; i++) {
                cout << "p: " << p << " i: "<< i << " f[p][i]: " << f[p][i] << endl;
                if (i == 4 || (i == 2 && (n / 10) % 10 == 6)) continue;
                ans += f[p][i];
            }
            n /= 10;
            p++;
        }
        cout << ans << endl;
    }
}
