//
//  main.cpp
//  cf26D
//
//  Created by eycia on 15/1/1.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m > n+1+k) {
        cout << 0 << endl;
        return 0;
    }
    double r1 = 1, r2 = 1;
    for (int i = m-k; i <= m; i++) {
        r1 *= i;
    }
    for (int i = n+1; i <= n+k+1; i++) {
        r2 *= i;
    }
    cout << 1 - r1 / r2 << endl;
    return 0;
}
