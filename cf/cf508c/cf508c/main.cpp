//
//  main.cpp
//  cf508c
//
//  Created by eycia on 15/1/28.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

bool light[700];
int offset = 350;

int main(int argc, const char * argv[]) {
    int m, t, r;
    int w;
    cin >> m >> t >> r;
    if (t < r) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> w;
        int tot = 0;
        for (int i = 1; i <= t; i++) {
            if (light[offset + w - i]) {
                tot++;
            }
        }
        for (int i = r - tot, j = 1; i > 0;) {
            if (!light[offset + w - j]) {
                light[offset + w - j] = true;
                i--;
            }
            j++;
        }
    }
    int tot = 0;
    for (int i = 0; i < 700; i++) {
        if (light[i]) {
            tot++;
        }
    }
    cout << tot << endl;
}
