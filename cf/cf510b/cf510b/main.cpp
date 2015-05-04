//
//  main.cpp
//  cf510b
//
//  Created by eycia on 15/2/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int fa[2505];

int n, m;

char mp[55][55];

inline int getf(int v) {
    return fa[v] < 0 ? v : fa[v] = getf(fa[v]);
}

inline bool merge(int x, int y) {
    if (getf(x) == getf(y)) {
        return true;
    }
    fa[getf(x)] = getf(y);
    return false;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }
    memset(fa, -1, sizeof(fa));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            if (mp[i][j] == mp[i][j+1]) {
                if (merge(i*m+j, i*m+j+1)) {
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == mp[i+1][j]) {
                if (merge(i*m+j, i*m+j+m)) {
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    int p = 0;
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << getf(p++) << "  ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mp[i][j];
        }
        cout << endl;
    }
    */
    puts("No");
    return 0;
}
