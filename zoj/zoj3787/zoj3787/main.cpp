//
//  main.cpp
//  13.L
//
//  Created by eycia on 26/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int > > ts;
vector<int> ans;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    int a, b, c;
    char o;
    while (t--) {
        int n, l;
        int tot = 0;
        ts.clear();
        ans.clear();
        cin >> n >> l;
        for (int i = 0; i < n; i++) {
            cin >> a >> o >> b >> o >> c;
            ts.push_back({a*3600+b*60+c, i+1});
        }
        sort(ts.begin(), ts.end());
        int fir = -30*3600;
        for (int i = 0; i < ts.size(); i++) {
            if (fir + l <= ts[i].first) {
                tot++;
                ans.push_back(ts[i].second);
                fir = ts[i].first;
            }
        }
        cout << tot << endl;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < tot-1; i++) {
            cout << ans[i] << " ";
        }
        cout << ans[tot-1];
        cout << endl;
    }
}