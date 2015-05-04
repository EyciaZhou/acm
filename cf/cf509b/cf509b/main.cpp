//
//  main.cpp
//  cf509b
//
//  Created by eycia on 15/1/31.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > r;

vector<int> r2;

int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    r.push_back({-10, -10});
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        r.push_back({k, i});
        r2.push_back(k);
    }
    sort(r.begin(), r.end());
    
    int kk = r[1].first;
    
    if (r[n].first - kk > k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < kk; j++) {
            cout << 1 << " ";
        }
        for (int j = 1; j <= r2[i] - kk; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}
