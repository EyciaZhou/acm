//
//  main.cpp
//  h
//
//  Created by eycia on 14-10-5.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
    int a, b, c;
    long long l = 0, r = 0, e = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        l += max(c - b, 0);
        r += max(c - a, 0);
        e += min(c, a) - max(c - b, 0);
    }
    if (l + e < r) {
        cout << l + e << endl;
    } else if (r + e < l) {
        cout << r + e << endl;
    } else {
        cout << (l + r + e) / 2 << endl;
    }
    }
}
