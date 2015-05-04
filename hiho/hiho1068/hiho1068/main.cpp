//
//  main.cpp
//  hiho1068
//
//  Created by eycia on 4/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int a[1000005];
int k[25][1000005];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        k[0][i] = a[i];
    }
    
    for (int j = 1; j <= 25; j++) {
        for (int i = 1; i <= n; i++) {
            if ((1 << (j-1))+i <= n)
                k[j][i] = min(k[j-1][i] , k[j-1][(1 << (j-1))+i]);
            else
                k[j][i] = k[j-1][i];
            //cout << k[j][i] << "    ";
        }
        //cout << endl;
    }
    int q, l, r;
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        int len = r - l + 1;
        int c = int(log(len) / log(2));
        //cout << c << " " << l << " " << r-(1<<c)+1 << endl;
        printf("%d\n", min(k[c][l], k[c][r-(1<<c)+1]));
        // 5 >> 2
        // 7 >> 2
        // 8 >> 3
        // 4 >> 2
        // 3 >> 1
    }
}
