//
//  main.cpp
//  bc29a
//
//  Created by eycia on 15/2/7.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

#define eps 1e-9

int main(int argc, const char * argv[]) {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        double l = b * log(a);
        double r = d * log(c);
        if (fabs(l-r) < eps) {
            cout << "=" << endl;
        } else if (l < r) {
            cout << "<" << endl;
        } else {
            cout << ">" << endl;
        }
    }
}
