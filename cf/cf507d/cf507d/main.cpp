//
//  main.cpp
//  cf507d
//
//  Created by eycia on 15/1/24.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

long long c[1005][105];
long long tenk[1005];
long long tenm[1005];

int main(int argc, const char * argv[]) {
    long long n, k, m;
    cin >> n >> k >> m;
    
    tenk[0] = tenm[0] = 1;
    for (int i = 1; i <= n; i++) {
        tenk[i] = (tenk[i-1] * 10) % k;
        tenm[i] = (tenm[i-1] * 10) % m;
    }
    
    for (int i = 1; i <= 9; i++) {
        c[1][i % k] += 1;
    }
    
    if (n == 1) {
        cout << c[n][0] % m << endl;
        return 0;
    }
    
    for (int i = 2; i < n; i++) {
        for (long long l = 0; l <= 9; l++) {
            for (long long j = 1; j < k; j++) {
                c[i][(j+l*tenk[i-1]) % k] = (c[i][(j+l*tenk[i-1]) % k] + c[i-1][j]) % m;
            }
            if (l > 0) {
                c[i][(l*tenk[i-1]) % k] = (c[i][(l*tenk[i-1]) % k] + 1) % m;
            }
        }
    }
    for (long long l = 1; l <= 9; l++) {
        for (long long j = 1; j < k; j++) {
            c[n][(j+l*tenk[n-1]) % k] = (c[n][(j+l*tenk[n-1]) % k] + c[n-1][j]) % m;
        }
        c[n][(l*tenk[n-1]) % k] = (c[n][(l*tenk[n-1]) % k] + 1) % m;
    }
    
    long long tot = 0;
    for (int i = 1; i < n; i++) {
        long long tmp = (tenm[n-i-1] * 9) % m;
        tot = (tot + (c[i][0] * tmp) % m) % m;
    }
    tot = (tot + c[n][0]) % m;
    cout << tot << endl;
}
//75594
/*
 3 27000
 21 18900
 147 13230
 1029 9261
 75594
 */
/*
 3 9391248
 21 45925488
 147 169878492
 1029 4457430432
 7203 9869003172
 50421 30529108764
 352947 186716021940
 2470629 5917798818540
 3240255 8365962540420
 3942921 2865162973860
 4176867 10087234049808
 1129773 3448442280636
 3223695 5514607404360
 3827001 4240347724008

*/