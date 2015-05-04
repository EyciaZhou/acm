//
//  main.cpp
//  cf507a
//
//  Created by eycia on 15/1/24.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> a[105];

int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    int tot = 0, j = 0;
    while  (tot <= k && j < n) {
        tot += a[j++].first;
    }
    if (tot <= k) {
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i].second << " ";
        }
    } else {
    cout << j - 1 << endl;
    for (int i = 0; i < j-1; i++) {
        cout << a[i].second << " ";
    }
    }
}
