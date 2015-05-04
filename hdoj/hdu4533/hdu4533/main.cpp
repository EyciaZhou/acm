//
//  main.cpp
//  hdu4533
//
//  Created by eycia on 14-9-24.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > ga;
vector<pair<int, int> > gb;

struct comp {
    inline bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return max(lhs.first, lhs.second) < max(rhs.first, rhs.second);
    }
};

int main(int argc, const char * argv[]) {
    int ff;
    int x1, y1, x2, y2;
    cin >> ff;
    while (ff--) {
        int n;
        ga.clear();
        gb.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            ga.push_back(pair<int, int>(x1, y1));
            ga.push_back(pair<int, int>(x2, y2));
            gb.push_back(pair<int, int>(x1, y2));
            gb.push_back(pair<int, int>(x2, y1));
        }
        sort(ga.begin(), ga.end());
        sort(gb.begin(), ga.end());
        for (int i = 0; i < gb.size(); i++) {
            cout << gb[i].first << " " << gb[i].second << endl;
        }
        int q, t;
        int i = 0, j = 0;
        long long tot = 0;
        cin >> q;
        while (q--) {
            cin >> t;
            while (max(ga[i].first, ga[i].second) <= t) {
                tot += t * t + ga[i].first * ga[i].second - t * ga[i].first - t * ga[i].second;
                i++;
            }
            while (max(gb[j].first, gb[j].second) <= t) {
                tot -= t * t + gb[j].first * gb[j].second - t * gb[j].first - t * gb[j].second;
                j++;
            }
            cout << tot << endl;
        }
    }
}
