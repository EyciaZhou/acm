//
//  main.cpp
//  hdu5131
//
//  Created by eycia on 14/12/24.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, string> > ps;
typedef pair<int, string> pis;

struct cmp2 {
    bool operator()(const pis &na, const pis &nb)
    {
        if (na.first == nb.first) {
            return na.second < nb.second;
        }
        return na.first > nb.first;
    }
};

int main(int argc, const char * argv[]) {
    int n, m;
    string s;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        ps.clear();
        for (int i = 0; i < n; i++) {
            cin >> s >> m;
            ps.push_back(make_pair(m, s));
        }
        sort(ps.begin(), ps.end(), cmp2());
        for (int i = 0; i < ps.size(); i++) {
            cout << ps[i].second << " " << ps[i].first << endl;
        }
        cin >> m;
        while (m--) {
            cin >> s;
            int ii = 0, ki = 0;
            for (int i = 0; i < ps.size(); i++) {
                if (ps[i].second == s) {
                    ii = i;
                    ki = ps[i].first;
                    break;
                }
            }
            int k2 = 0;
            for (int i = 0; i < ps.size(); i++) {
                if (ps[i].first == ki) {
                    k2 = i;
                    break;
                }
            }
            cout << k2 + 1;
            if (k2 != ii) {
                cout << " " << ii - k2 + 1;
            }
            cout << endl;
        }
    }
    
}
