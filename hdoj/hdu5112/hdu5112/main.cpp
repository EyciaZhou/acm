//
//  main.cpp
//  hdu5112
//
//  Created by eycia on 14/11/29.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct rec {
    int t;
    int p;
    
    inline bool operator<(const rec& a) const
    {
        return t < a.t;
    }
} recs[10000];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &recs[i].t, &recs[i].p);
        }
        sort(recs, recs+n);
        float ma = -1;
        for (int i = 1; i < n; i++) {
            if (fabs((recs[i].p - recs[i-1].p) / (recs[i].t - recs[i-1].t + 0.0)) > ma) {
                ma = fabs((recs[i].p - recs[i-1].p) / (recs[i].t - recs[i-1].t + 0.0));
            }
        }
        printf("Case #%d: %0.2f\n", tt, ma);
    }
}
