//
//  main.cpp
//  cfgym100571b
//
//  Created by eycia on 15/1/21.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

long long f[100005];
long long p1[100005];
long long p2[100005];
long long m1[100005];
long long m2[100005];
long long x[100005];
long long x2[100005];

#define MOD 1000000007

int main(int argc, const char * argv[]) {
    long long n, q, a, b, l, r;
    cin >> n >> q;
    cin >> f[1] >> f[2];
    cin >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> x2[i];
    }
    for (int i = 3; i < n+5; i++) {
        f[i] = ((f[i-1] * b) % MOD + (f[i-2] * a) % MOD) % MOD;
    }
    while (q--) {
        cin >> l >> r;
        p1[l] += f[1];
        p2[l+1] += f[2];
        p1[l+1] -= f[1]*b;
        
        if (l == r) {
            p1[r+1] -= f[r-l+1];
            p2[r+1] -= f[r-l];
        } else {
        
            m1[r+1] -= f[r-l+1];
            
            m2[r+1] -= f[r-l];
        }
        m2[r+2] -= f[r-l+1];
    }
    x[1] = p1[1]  + p2[1] ;
    x2[1] += x[1];
    for (int i = 2; i <= n+5; i++) {
        x[i] = (((x[i-1] + m1[i]) * b) % MOD + ((x[i-2] + m2[i]) * a) % MOD + p1[i] + p2[i]) % MOD;
        x2[i] = (x2[i] + x[i]) % MOD;
        while (x2[i] < 0) {
            x2[i] += MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        //cout << f[i] << "\t" << p1[i] << "\t" << p2[i] << "\t" << m1[i] << "\t" << m2[i] << "\t";
        cout << x2[i] << " ";
    }
}
/*
 8 2
 1 1
 3 2
 0 0 0 0 0 0 0 0
 1 6
 4 5
 
 6 2
 1 1
 2 3
 0 0 0 0 0 0
 1 6
 1 1
 4 5
 2 2
 4 4
 5 6
 
 1      2	0	0       0	2
 1      0	2	-3      0	1000000006
 5      0	0	0       -1	1000000006
 17     0	0	0       0	1000000002
 61     0	0	0       0       999999990
 217	0	0	0       0       999999946
 773	0	0	-217	-61     999999017
 2753	0	0	0       -217	999996481
 9805	0	0	0       0       999987449
 34921	0	0	0       0       999955281
 0      0	0	0       0       999840713
*/