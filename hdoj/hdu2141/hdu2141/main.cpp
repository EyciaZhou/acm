//
//  main.cpp
//  hdu2141
//
//  Created by eycia on 14-9-16.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int aa[505], bb[505], cc[505];
int dd[250005];

int main(int argc, const char * argv[]) {
    int a, b, c;
    int ff = 0;
    while (cin >> a >> b >> c) {
        cout << "Case " << ++ff << ":" << endl;
        for (int i = 0; i < a; i++) {
            cin >> aa[i];
        }
        for (int i = 0; i < b; i++){
            cin >> bb[i];
        }
        for (int i = 0; i < c; i++) {
            cin >> cc[i];
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                dd[i * b + j] = aa[i] + bb[j];
            }
        }
        sort(dd, dd + a * b);
        int x, t;
        cin >> x;
        for (int i = 0; i < x; i++) {
            cin >> t;
            bool flag = false;
            for (int j = 0; j < c; j++) {
                if (*lower_bound(dd, dd + a * b, t - cc[j]) ==  t - cc[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}