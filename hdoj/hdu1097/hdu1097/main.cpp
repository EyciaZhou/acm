//
//  main.cpp
//  hdu1097
//
//  Created by eycia on 14/10/19.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int exp(int base, int up) {
    base = base % 10;
    int mod = 10;
    int res = 1;
    int tmp = base;
    while (up) {
        if (up & 1) {
            res = res * tmp % mod;
        }
        tmp = tmp * tmp % mod;
        up >>= 1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int n, m;
    while (cin >> n >> m) {
        cout << exp(n, m) << endl;
    }
}
