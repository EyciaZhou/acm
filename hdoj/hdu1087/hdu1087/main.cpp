//
//  main.cpp
//  hdu1087
//
//  Created by eycia on 14/11/14.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int raw[1005];
int far[1005];

int main(int argc, const char * argv[]) {
    int n;
    while (true) {
        cin >> n;
        if (!n) {
            break;
        }
        memset(far, 0, sizeof(far));
        for (int i = 1; i <= n; i++) {
            cin >> raw[i];
        }
        int mm = 0;
        raw[0] = 0;
        for (int i = 1; i <= n; i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (far[j] > max && raw[i] > raw[j]) {
                    max = far[j];
                }
            }
            far[i] = max + raw[i];
            if (far[i] > mm) {
                mm = far[i];
            }
        }
        cout << mm << endl;
    }
}
