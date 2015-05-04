//
//  main.cpp
//  cf292a
//
//  Created by eycia on 15/2/18.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b, s;
    cin >> a >> b >> s;
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    if (s < a + b || (s-a-b) % 2 != 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}