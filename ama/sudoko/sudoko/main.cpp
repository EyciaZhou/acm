//
//  main.cpp
//  sudoko
//
//  Created by eycia on 14/11/11.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int ss[9][9];
int h[9];
int s[9];
int f[9];

void update(int i, int j, int d) {
    h[i] = h[i] | (1 << d);
    s[j] = s[j] | (1 << d);
    f[i / 3 + j / 3 * 3] = f[i / 3 + j / 3 * 3] | (1 << d);
}

void remove(int i, int j, int d) {
    h[i] = h[i] ^(1 << d);
    s[j] = s[j] ^ (1 << d);
    f[i / 3 + j / 3 * 3] = f[i / 3 + j / 3 * 3] ^ (1 << d);
}

bool ok(int i, int j, int d) {
    return !((h[i] & (1 << d)) | (s[j] & (1 << d)) | (f[i / 3 + j / 3 * 3] & (1 << d)));
}

void dfs() {
    int tot = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (ss[i][j] != 0) {
                tot++;
            }
        }
    }
    if (tot == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << ss[i][j] << "   ";
            }
            cout << endl;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (ss[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (ok(i, j, k)) {
                        update(i, j, k);
                        ss[i][j] = k;
                        dfs();
                        ss[i][j] = 0;
                        remove(i, j, k);
                    }
                }
                return;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> ss[i][j];
            update(i, j, ss[i][j]);
        }
    }
    dfs();
}
