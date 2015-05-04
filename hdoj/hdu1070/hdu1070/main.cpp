//
//  main.cpp
//  hdu1070
//
//  Created by eycia on 15/1/21.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, k, volum;
    double cost;
    string tn, rn;
    cin >> n;
    while (n--) {
        double mincost = 0x7fffffff;
        int mvolum=-1;
        cin >> k;
        while (k--) {
            cin >> tn >> cost >> volum;
            int days = min(volum / 200, 5);
            if (days == 0) continue;
            if (cost / days < mincost || (cost / days == mincost && mvolum < volum)) {
                mincost = cost / days;
                rn = tn;
                mvolum = volum;
            }
        }
        cout << rn << endl;
    }
}
