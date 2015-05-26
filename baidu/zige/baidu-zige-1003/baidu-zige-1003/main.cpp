//
//  main.cpp
//  baidu-zige-1003
//
//  Created by eycia on 24/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <set>
using namespace std;

#define p pair
#define ia p<p<int, int>, p<int, int> >
#define a1 first.first
#define a2 first.second
#define a3 second.first
#define a4 second.second
#define mp make_pair

vector<ia > ip;
set<ia > tmp;

int main(int argc, const char * argv[]) {
    int t, n, m;
    int a, b, c, d;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        printf("Case #%d:\n", ff);
        scanf("%d %d", &n, &m);
        ip.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d.%d.%d.%d", &a, &b, &c, &d);
            ip.push_back(mp(mp(a, b), mp(c, d)));
        }
        for (int i = 0; i < m; i++) {
            scanf("%d.%d.%d.%d", &a, &b, &c, &d);
            tmp.clear();
            for (int i = 0; i < ip.size(); i++) {
                tmp.insert(mp(mp(a&ip[i].a1, b&ip[i].a2), mp(c&ip[i].a3, d&ip[i].a4)));
            }
            printf("%lu\n", tmp.size());
        }
    }
}
