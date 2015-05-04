//
//  main.cpp
//  快速幂
//
//  Created by eycia on 14/10/20.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>

int exp(int base, int up, int mod) {
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
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
