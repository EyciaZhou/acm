//
//  main.cpp
//  cf507c
//
//  Created by eycia on 15/1/24.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    long long h, n;
    cin >> h >> n;
    long long nn = 0;
    n--;
    
    for (int i = 0; i < h; i++) {
        nn = nn * 2 + n % 2;
        n /= 2;
    }
    long long now = 0;
    long long te = ((long long)(1) << h);
    bool r = true;
    for (int i = 0; i < h; i++) {
        if (nn%2 ^ r) {
            now ++;
        } else {
            now += te;
            r = !r;
        }
        r = !r;
        te /= 2;
        nn /= 2;
    }
    cout << now;
}
