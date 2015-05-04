//
//  main.cpp
//  cf505b
//
//  Created by eycia on 15/1/22.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int f[105][105];

int getf(int k, int v) {
    return f[k][v] < 0 ? v : f[k][v] = getf(k, f[k][v]);
}

int main(int argc, const char * argv[]) {
    int n, m, q;
    int u, v, c;
    memset(f, -1, sizeof(f));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        if (getf(c, u) != getf(c, v)) {
            f[c][getf(c, u)] = getf(c, v);
        }
    }
    cin >> q;
    while (q--) {
        cin >> u >> v;
        int count = 0;
        for (int i = 1; i <= 100; i++) {
            if (getf(i, u) == getf(i, v)) {
                count ++;
            }
        }
        cout << count << endl;
    }
}
