//
//  main.cpp
//  cfgym100571a
//
//  Created by eycia on 15/1/21.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

//0 1 3 6 10 15

#include <iostream>
#include <algorithm>
using namespace std;

long long a[100005];

int main(int argc, const char * argv[]) {
    int n, q;
    long long query, tot = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
        a[i] += a[i-1];
    }
    for (int i = 0; i < q; i++) {
        cin >> query;
        cout << upper_bound(a, a+n+1, query % tot) - a << endl;
    }
}
