//
//  main.cpp
//  cf509a
//
//  Created by eycia on 15/1/31.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

long long mm[15][15];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < 15; i++) {
        mm[1][i] = 1;
        mm[i][1] = 1;
    }
    for (int i = 2; i < 15; i++) {
        for (int j = 2; j < 15; j++) {
            mm[i][j] = mm[i-1][j] + mm[i][j-1];
        }
    }
    cout << mm[n][n];
}
