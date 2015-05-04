//
//  main.cpp
//  bc17.1
//
//  Created by eycia on 14/11/8.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int res2(int l, int k) {
    if (k > l) {
        return 0;
    }
    if (l % k == 0) {
        return l * l;
    }
    int bb = int((l - 0.00001) / k) * k;
    
    return 4 * bb * (l % bb);
}

int doo(int l, int k) {
    if (k > l) {
        return 0;
    }
    if (l % k == 0) {
        return l * l;
    }
    return max(res2(l, k) + doo(l - l % k * 2, k), l * l - (l % k) * (l % k));
}

int main(int argc, const char * argv[]) {
    int ff;
    int a, b;
    cin >> ff;
    while (ff--) {
        cin >> a >> b;
        int result = 0;
        
        if (a % b == 0) {
            cout << a * a << endl;
            continue;
        }
        
        cout << doo(a, b) << endl;
    }
}
