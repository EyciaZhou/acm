//
//  main.cpp
//  13.1
//
//  Created by eycia on 26/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        int t1 = 0, t2 = 0;
        int tmp;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            t1 += tmp;
        }
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            t2 += tmp;
        }
        if (t1 > t2) {
            cout << "Calem" << endl;
        } else if (t1 == t2) {
            cout << "Draw" << endl;
        } else {
            cout << "Serena" << endl;
        }
    }
    return 0;
}