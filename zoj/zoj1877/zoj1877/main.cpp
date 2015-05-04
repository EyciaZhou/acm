//
//  main.cpp
//  zoj1877
//
//  Created by eycia on 14-9-10.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int a[1005], f[1005];
    bool g[1005];
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        f[1] = a[0];
        f[2] = a[1];
        f[3] = a[0] + a[1] + a[2];
        for (int i = 4; i <= n; i++) {
            f[i] = f[i-1] + a[0] + a[i-1];
            g[i] = false;
            if (f[i-2] + a[0] + 2 * a[1] + a[i-1] < f[i]) {
                f[i] = f[i-2] + a[0] + 2 * a[1] + a[i-1];
                g[i] = true;
            }
        }
        cout << f[n] << endl;
        while (n > 3) {
            if (g[n]) {
                cout << a[0] << " " << a[1] << endl;
                cout << a[1] << endl;
                cout << a[n-2] << " " << a[n-1] << endl;
                cout << a[0] << endl;
                n -= 2;
            } else {
                cout << a[0] << " " << a[n-1] << endl;
                cout << a[0] << endl;
                n -= 1;
            }
        }
        switch (n) {
            case 3 :
                cout << a[0] << " " << a[2] << endl;
                cout << a[0] << endl;
                cout << a[0] << " " << a[1] << endl;
                break;
            case 2:
                cout << a[0] << " " << a[1] << endl;
                break;
            default:
                cout << a[0] << endl;
        }
    }
    return 0;
}
