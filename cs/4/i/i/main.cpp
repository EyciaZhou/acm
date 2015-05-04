//
//  main.cpp
//  i
//
//  Created by eycia on 14-10-5.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n, s;
    while (cin >> n >> s) {
        long long max = (n-1) * n / 2;
        if (s < 0) {
            s = -s;
        }
        if (s > max) {
            cout << "No" << endl;
            continue;
        }
        if ((max % 2) ^ (s % 2)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
