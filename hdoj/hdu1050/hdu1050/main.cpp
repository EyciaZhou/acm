//
//  main.cpp
//  hdu1050
//
//  Created by eycia on 14-9-9.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int ff, t1, t2;
    cin >> ff;
    int rr[205];
    while (ff--) {
        int t;
        cin >> t;
        for (int i = 0; i < 205; i++) {
            rr[i] = 0;
        }
        for (int i = 0; i < t; i++) {
            cin >> t1 >> t2;
            if (t1 > t2) swap(t1, t2);
            for (int i = (t1 + 1) / 2; i <= (t2 + 1) / 2; i++) {
                rr[i]++;
            }
        }
        int max = 0;
        for (int i = 0; i < 205; i++) {
            if (rr[i] > max) {
                max = rr[i];
            }
        }
        cout << max * 10 << endl;
    }
    return 0;
}
