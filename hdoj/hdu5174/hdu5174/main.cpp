//
//  main.cpp
//  hdu5174
//
//  Created by eycia on 15/2/14.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int a[200];

map<unsigned int, unsigned int> vv;
vector<pair<unsigned int, unsigned int> > vs;

int main(int argc, const char * argv[]) {
    int n, te;
    int ff = 1;
    while (cin >> n) {
        
        vv.clear();
        vs.clear();
        for (int i = 0; i < n; i++) {
            cin >> te;
            vv[te] = vv[te]+1;
        }
        
        for (map<unsigned int, unsigned int>::iterator it = vv.begin(); it != vv.end(); it++) {
            vs.push_back(*it);
        }
        int tot = 0;
        int le = vs.size();
        
        if (le == 1) {
            cout << "Case #" << ff++ << ": " << -1 << endl;
            continue;
        }

        for (int i = 0; i < vs.size(); i++) {
            if ((vs[(i+le-1)%le].first + vs[i].first) % 2147483647 == vs[(i+1)%le].first) {
                tot += vs[i].second;
            }
        }
        cout << "Case #" << ff++ << ": " << tot << endl;
    }
}
