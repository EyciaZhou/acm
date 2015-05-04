//
//  main.cpp
//  cf500B
//
//  Created by eycia on 15/1/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int p[305];
bool mm[305][305];

int main(int argc, const char * argv[]) {
    int n;
    char ch;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ch;
            if (ch == '1') {
                mm[i][j] = true;
            } else {
                mm[i][j] = false;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mm[i][k] && mm[k][j]) {
                    mm[i][j] = true;
                }
            }
        }
    }
    while (true) {
        bool chg = false;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (mm[i][j] && p[i] > p[j]) {
                    swap(p[i], p[j]);
                    chg = true;
                }
            }
        }
        if (!chg) break;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}
