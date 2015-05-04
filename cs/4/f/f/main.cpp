//
//  main.cpp
//  f
//
//  Created by eycia on 14-10-5.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
double aa[5000005];

int main(int argc, const char * argv[]) {
    aa[0] = -1;
    for (int i = 1; i < 5000005; i++) {
        aa[i] = aa[i-1] + sqrt(1 + 4 * i);
    }
    int ff;
    cin >> ff;
    int n;
    while (ff--) {
        cin >> n;
        printf("%.3lf\n", aa[n - 1] / n / 2 + 0.5);
        //cout << aa[n - 1] / n / 2 + 0.5 << endl;
    }
}
