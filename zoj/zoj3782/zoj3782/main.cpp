//
//  main.cpp
//  13.G
//
//  Created by eycia on 26/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int yx[1000];

int f(char o, int l, int r) {
    switch (o) {
        case '+':
            return l+r;
            break;
        case '-':
            return l-r;
            break;
        case '*':
            return l*r;
            break;
        case '/':
            return l/r;
            break;
        case '%':
            return l%r;
            break;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int t;
    char o1, o2;
    int v1, v2, v3;
    cin >> t;
    yx['+'] = 0;
    yx['-'] = 0;
    yx['*'] = 1;
    yx['/'] = 1;
    yx['%'] = 1;
    while (t--) {
        cin >> v1 >> o1 >> v2 >> o2 >> v3;
        if (yx[o1] < yx[o2]) {
            cout << f(o1, v1, f(o2, v2, v3)) << endl;
        } else {
            cout << f(o2, f(o1, v1, v2), v3) << endl;
        }
    }
}