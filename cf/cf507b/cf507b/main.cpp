//
//  main.cpp
//  cf507b
//
//  Created by eycia on 15/1/24.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    long long r, x, y, xx, yy;
    cin >> r >> x >> y >> xx >> yy;
    cout << (long long)(sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y)) / 2 / r + 0.9999999999999) << endl;
}
