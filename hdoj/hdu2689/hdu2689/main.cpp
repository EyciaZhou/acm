//
//  main.cpp
//  hdu2689
//
//  Created by eycia on 14/10/19.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int a[1005];

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int tot = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                    tot++;
                }
            }
        }
        cout << tot << endl;
    }
}
