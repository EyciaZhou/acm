//
//  main.cpp
//  hdu5063
//
//  Created by eycia on 14-10-16.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> trans;
vector<pair<int, int> > query;

long long exp(int base, int up, int mod) {
    long long res = 1;
    long long tmp = base;
    while (up) {
        if (up & 1) {
            res = res * tmp % mod;
        }
        tmp = tmp * tmp % mod;
        up >>= 1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n, m;
        char tc;
        int ti;
        trans.clear();
        query.clear();
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            getchar();
            scanf("%c %d", &tc, &ti);
            if (tc == 'O') {
                trans.push_back(ti);
            } else {
                query.push_back(make_pair(trans.size() - 1, ti));
            }
        }
        for (int i = 0; i < query.size(); i++) {
            int mu = 0;
            int pos = query[i].second;
            for (int j = query[i].first; j >= 0; j--) {
                if (trans[j] == 3) {
                    mu++;
                }
                if (trans[j] == 2) {
                    pos = n + 1 - pos;
                }
                if (trans[j] == 1) {
                    if (pos <= (n + 1) / 2) {
                        pos = pos * 2 - 1;
                    } else {
                        pos = (pos - (n + 1) / 2) * 2;
                    }
                }
            }
            long long temp = pos;
            for (int i = 0; i < mu; i++) {
                temp = temp * temp % 1000000007;
            }
            printf("%lld\n", temp);
        }
    }
}
