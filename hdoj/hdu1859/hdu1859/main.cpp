//
//  main.cpp
//  hdu1859
//
//  Created by eycia on 14/11/2.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int x, y;
    int len;
    while (true) {
        len = 0;
        int ml = -100000;
        int mt = -100000;
        int mr = 100000;
        int mb = 100000;
        while (true) {
            cin >> x >> y;
            len++;
            if (x == 0 && y == 0) {
                if (len > 1) {
                    break;
                } else {
                    return 0;
                }
            }
            if (x > ml) {
                ml = x;
            }
            if (x < mr) {
                mr = x;
            }
            if (y > mt) {
                mt = y;
            }
            if (y < mb) {
                mb = y;
            }
        }
        cout << mr << " " << mb << " " << ml << " " << mt << endl;
    }
}
