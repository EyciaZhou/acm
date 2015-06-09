//
//  main.cpp
//  bdzxfs.1
//
//  Created by eycia on 6/6/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool pt[2010][2010];
#define offset 1005
#define mp make_pair
#define xx first
#define yy second
#define p1 first
#define p2 second
vector<pair<pair<int, int>, pair<int, int> > > ps;
vector<pair<int, int> > qq;

inline bool ish(int i) {
    if (ps[i].p1.xx == ps[i].p2.xx) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int t, n, x1, x2, y1, y2;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        memset(pt, false, sizeof(pt));
        qq.clear();
        ps.clear();
        printf("Case #%d:\n", ff);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            ps.push_back(mp(mp(x1, y1), mp(x2, y2)));
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (ish(i) ^ (ish(j))) {
                    if (ish(i)) {
                        if ((ps[j].p1.yy < ps[i].p1.yy && ps[j].p2.yy > ps[i].p1.yy) ||
                            (ps[j].p2.yy < ps[i].p1.yy && ps[j].p1.yy > ps[i].p1.yy)) {
                            if ((ps[i].p1.xx < ps[j].p1.xx && ps[i].p2.xx > ps[j].p1.xx) ||
                                (ps[i].p2.xx < ps[j].p1.xx && ps[i].p1.xx > ps[j].p1.xx)) {
                                
                                int csx = ps[j].p1.xx;
                                int csy = ps[i].p1.yy;
                                qq.push_back(mp(csx, csy));
                                pt[csx+offset][csy+offset] = true;
                            }
                        }
                    }
                    if (ish(j)) {
                        if ((ps[i].p1.yy < ps[j].p1.yy && ps[i].p2.yy > ps[j].p1.yy) ||
                            (ps[i].p2.yy < ps[j].p1.yy && ps[i].p1.yy > ps[j].p1.yy)) {
                            if ((ps[j].p1.xx < ps[i].p1.xx && ps[j].p2.xx > ps[i].p1.xx) ||
                                (ps[j].p2.xx < ps[i].p1.xx && ps[j].p1.xx > ps[i].p1.xx)) {
                                int csx = ps[i].p1.xx;
                                int csy = ps[j].p1.yy;
                                qq.push_back(mp(csx, csy));
                                pt[csx+offset][csy+offset] = true;
                            }
                        }
                    }
                }
            }
        }
        int tot = 0;
        for (int i = 0; i < qq.size(); i++) {
            for (int j = 0 ; j < qq.size(); j++) {
                if (qq[i].xx != qq[j].xx && qq[i].yy != qq[j].yy) {
                    if (pt[qq[i].xx+offset][qq[j].yy+offset] && pt[qq[j].xx+offset][qq[i].yy+offset]) {
                        tot++;
                    }
                }
            }
        }
        printf("%d\n", tot/4);
    }
}
