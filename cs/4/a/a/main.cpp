//
//  main.cpp
//  a
//
//  Created by eycia on 14-10-5.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, dn;
    while (cin >> n >> dn) {
        int ans = 1;
        int t1 = -1, t2 = -1;
        for (int i = 0; i < dn; i++) {
            cin >> t1;
            if (t1 <= t2) {
                ans++;
            }
            t2 = t1;
        }
        cout << ans << endl;
    }
}
