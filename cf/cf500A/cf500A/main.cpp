//
//  main.cpp
//  cf500A
//
//  Created by eycia on 15/1/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

bool v[30005];
int j[30005];

int main(int argc, const char * argv[]) {
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n-1; i++) {
        cin >> j[i];
    }
    j[n]=100;
    int now = 1;
    while (true) {
        if (v[now]) break;
        if (now < 1 || now > n) break;
        v[now] = true;
        now += j[now];
    }
    cout << (v[t] ? "YES\n" : "NO\n");
}
