//
//  main.cpp
//  zzboj1002
//
//  Created by eycia on 21/4/15.
//  Copyright (c) 2015 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int res[1005];
int f[1005];

void init() {
    for (int i = 1; i <= 1000; i++) {
        int tot = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                tot += j;
            }
        }
        res[i] = tot;
    }
}

int main(int argc, const char * argv[]) {
    
    init();
    
    int s;
    cin >> s;
    
    
    for (int i = 0; i < 1005; i++) {
        f[i] = 0;
    }
    
    for (int i = 1; i <= s; i++) {
        for (int j = s; j >= i; j--) {
            if (f[j - i] + res[i] > f[j]) {
                f[j] = f[j - i] + res[i];
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < 1005; i++) {
        if (f[i] > mx) {
            mx = f[i];
        }
    }
    cout << mx << endl;
}