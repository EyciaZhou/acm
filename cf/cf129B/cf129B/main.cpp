//
//  main.cpp
//  cf129B
//
//  Created by eycia on 10/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int g[200][200];
int cc[200];

int n, m;

bool find() {
    bool flag = false;
    int bb[200];
    for (int i = 1; i <= n; i++) {
        bb[i] = cc[i];
    }
    for (int i = 1; i <= n; i++) {
        if (bb[i] == 1) {
            flag = true;
            cc[i]--;
            for (int j = 1; j <= n; j++) {
                if (g[i][j] > 0) {
                    g[i][j] = 0;
                    g[j][i] = 0;
                    cc[j]--;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        bb[i] = cc[i];
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    int u, v;
    cin >> n >> m;
    for  (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
        cc[u]++;
        cc[v]++;
    }
    int tot = 0;
    while (find()) {
        tot++;
    }
    cout << tot << endl;
}
