//
//  main.cpp
//  cf510d
//
//  Created by eycia on 15/2/6.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long long v[305], w[305];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    //pos, cost
    map<long long, long long> dp;
    
    for (int i = 0; i < n; i++) {
        if (dp[v[i]] == 0 || dp[v[i]] > w[i]) {
            dp[v[i]] = w[i];
        }
        for (map<long long, long long>::iterator it = dp.begin(); it != dp.end(); it++) {
            long long target = __gcd(it->first, v[i]);
            long long cost = it->second + w[i];
            if (dp[target] == 0 || dp[target] > cost) {
                dp[target] = cost;
            }
        }
    }
    
    if (dp[1] > 0) {
        cout << dp[1] << endl;
    } else {
        cout << -1 << endl;
    }
}
