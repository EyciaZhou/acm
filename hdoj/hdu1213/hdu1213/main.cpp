//
//  main.cpp
//  hdu1213
//
//  Created by eycia on 14-9-23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int fa[1005];
inline int getf(int s) {
    if (fa[s] == s) {
        return s;
    }
    int t = s;
    while (fa[t] != t) {
        t = fa[t];
    }
    fa[s] = t;
    while (fa[s] != s) {
        s = fa[s];
        fa[s] = t;
    }
    return t;
}

int main(int argc, const char * argv[]) {
    int ff, a, b;
    cin >> ff;
    while (ff--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            fa[getf(a)] = getf(b);
        }
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == i) {
                tot++;
            }
        }
        cout << tot << endl;
    }
}
