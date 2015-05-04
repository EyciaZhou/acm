//
//  main.cpp
//  cf510a
//
//  Created by eycia on 15/2/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                putchar('#');
            }
        } else {
            if (i / 2 % 2 == 1) {
                putchar('#');
            }
            for (int j = 0; j < m-1; j++) {
                putchar('.');
            }
            if (i / 2 % 2 == 0) {
                putchar('#');
            }
        }
        putchar('\n');
    }
}
