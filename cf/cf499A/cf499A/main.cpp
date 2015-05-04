//
//  main.cpp
//  a
//
//  Created by Serx on 14/12/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, x;
    int aa, bb;
    cin >> n >> x;
    int pos = 1;
    int ti = 0;
    for (int i = 0; i < n; i++) {
        cin >> aa >> bb;
        while (pos+x <= aa) {
            pos += x;
        }
        ti += bb-pos+1;
        pos = bb+1;
    }
    cout << ti << endl;
}