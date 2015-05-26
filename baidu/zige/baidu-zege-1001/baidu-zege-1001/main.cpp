//
//  main.cpp
//  baidu-zege-1001
//
//  Created by eycia on 24/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

#define MOD 1000000007

long long f[1000005];

int main(int argc, const char * argv[]) {
    int t;
    long long n;
    cin >> t;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < 1000005; i++) {
        f[i] = (f[i-1] + ((i-1)*f[i-2]) % MOD) % MOD;
    }
    for (int ff = 1; ff <= t; ff++) {
        cin >> n;
        cout << "Case #" << ff << ":" << endl;
        cout << f[n] << endl;
    }
}
