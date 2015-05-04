//
//  main.cpp
//  hdu5137
//
//  Created by eycia on 14/12/24.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int mat[40][40];

bool vi[40];

int n;


int spfa() {
    queue<int > q;
    q.push(1);
    int d[40];
    for (int i = 0; i < 40; i++) {
        d[i] = 0x7fffffff;
    }
    d[1] = 0;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (int i = 2; i <= n; i++) {
            if (!vi[i] && mat[k][i] >= 0 && d[i] > d[k] + mat[k][i]) {
                d[i] = d[k] + mat[k][i];
                q.push(i);
            }
        }
    }
    return d[n];
}

int main(int argc, const char * argv[]) {
    int m;
    int s, t, v;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        memset(vi, false, sizeof(vi));
        memset(mat, -1, sizeof(mat));
        for (int i = 0; i < m; i++) {
            cin >> s >> t >> v;
            mat[s][t] = v;
            mat[t][s] = v;
        }
        vi[1] = true;
        int max = 0;
        for (int i = 2; i < n; i++) {
            vi[i] = true;
            int mid = spfa();
            vi[i] = false;
            if (mid > max) {
                max = mid;
            }
        }
        if (max == 0x7fffffff) {
            cout << "Inf" << endl;
        } else {
            cout << max << endl;
        }
    }
}
