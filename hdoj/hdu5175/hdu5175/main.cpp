//
//  main.cpp
//  hdu5175
//
//  Created by eycia on 15/2/14.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<long long> ans;

int main(int argc, const char * argv[]) {
    long long n;
    int ff = 1;
    while (cin >> n) {
        ans.clear();
        for (long long i = 1; i <= sqrt(n); i++) { // ans is n ^ i
            if (n % i == 0) {
                long long v = n ^ i;
                if (v <= n && v > 0 && v % i == 0) {
                    ans.push_back(v);
                }
                v = n ^ (n/i);
                if (v <= n && v > 0 && v % (n/i) == 0) {
                    ans.push_back(v);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        
        cout << "Case #" << ff++ << ":\n";
        cout << ans.size() << endl;
        int le  = ans.size();
        for (int i = 0; i < le - 1; i++) {
            cout << ans[i] << " ";
        }
        if (le >= 1) {
            cout << ans[le-1];
        }
        cout << endl;
    }
}
