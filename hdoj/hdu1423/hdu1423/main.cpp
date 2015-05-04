//
//  main.cpp
//  hdu1423
//
//  Created by eycia on 14/11/14.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int res[505][505];

int main(int argc, const char * argv[]) {
    int ff;
    cin >> ff;
    for (int tt = 0; tt < ff; tt++) {
        int f1, f2;
        int d1[505], d2[505];
        cin >> f1;
        for (int i = 1; i <= f1; i++) {
            cin >> d1[i];
        }
        cin >> f2;
        for (int i = 1; i <= f2; i++) {
            cin >> d2[i];
        }
        
        int mm = 0;
        memset(res, 0, sizeof(res));
        for (int i = 1; i <= f1; i++) {
            for (int j = 1; j <= f2; j++) {
                if (d1[i] == d2[j]) {
                    int ma = 0;
                    for (int k = 1; k < j; k++) {
                        if (res[i-1][k] > ma && d2[j] > d2[k]) {
                            ma = res[i-1][k];
                        }
                    }
                    res[i][j] = ma + 1;
                } else {
                    res[i][j] = max(res[i-1][j], res[i][j-1]);
                }
                if (res[i][j] > mm) {
                    mm = res[i][j];
                }
            }
        }
        cout << mm << endl;
        if (tt != ff-1) {
            cout << endl;
        }
    }
}
