//
//  main.cpp
//  cf515b
//
//  Created by eycia on 15/2/18.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

bool ha[2][105];

int main(int argc, const char * argv[]) {
    int nu[2], a, b;
    queue<int> q[2];
    for (int i = 0; i <= 1; i++) {
        cin >> nu[i];
    }
    for (int i = 0; i <= 1; i++) {
        cin >> a;
        while (a--) {
            cin >> b;
            q[i].push(b);
            ha[i][b] = true;
        }
    }
    int i = 0;
    while (!q[0].empty() || !q[1].empty()) {
        while (!q[i].empty()) {
            int k = q[i].front() % nu[i^1];
            int t = k;
            q[i].pop();
            do {
                if (!ha[i^1][k]) {
                    q[i^1].push(k);
                    ha[i^1][k] = true;
                }
                k = (k + nu[i]) % nu[i^1];
            } while (k != t);
        }
        i = i ^ 1;
    }
    bool flag = false;
    for (int k = 0; k <= 1; k++) {
        for (int i = 0; i < nu[k]; i++) {
            if (!ha[k][i]) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
