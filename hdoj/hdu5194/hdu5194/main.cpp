//
//  main.cpp
//  hdu5194
//
//  Created by eycia on 28/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    while (cin >> n >> m) {
        int l = n * m;
        int r = n + m;
        cout << l / __gcd(l, r) << "/" << r / __gcd(l, r) << endl;
    }
}