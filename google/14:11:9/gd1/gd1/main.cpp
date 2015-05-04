//
//  main.cpp
//  gd1
//
//  Created by eycia on 14/11/9.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int sti[4] = {0, 0, 1, -1};
int stj[4] = {1, -1, 0, 0};

int n;

int vv[1005][1005];
int mm[1005][1005];

int find(int xx, int yy) {
    for (int i = 0; i < 4; i++) {
        if (xx + sti[i] > 0 && xx + sti[i] <= n && yy + stj[i] > 0 && yy+stj[i] <= n) {
            if (mm[xx+sti[i]][yy+stj[i]] == mm[xx][yy] + 1) {
                if (vv[xx+sti[i]][yy+stj[i]] < 0) {
                    find(xx+sti[i], yy+stj[i]);
                }
                vv[xx][yy] = vv[xx+sti[i]][yy+stj[i]] + 1;
                return vv[xx+sti[i]][yy+stj[i]] + 1;
            }
        }
    }
    vv[xx][yy] = 1;
    return 1;
}

int main(int argc, const char * argv[]) {
    int ff;
    cin >> ff;
    for (int tt = 1; tt <= ff; tt++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mm[i][j];
                vv[i][j] = -1;
            }
        }
        int max = -1;
        int maxj = 0;
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int k = find(i, j);
                if (k == max) {
                    if (mm[i][j] < mm[maxi][maxj]) {
                        max = k;
                        maxi = i;
                        maxj = j;
                    }
                }
                if (k > max) {
                    max = k;
                    maxi = i;
                    maxj = j;
                }
                
            }
        }
        cout << "Case #" << tt << ": " << mm[maxi][maxj] << " " << max << endl;
    }
}
