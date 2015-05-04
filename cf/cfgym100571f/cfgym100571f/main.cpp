//
//  main.cpp
//  cfgym100571f
//
//  Created by eycia on 15/1/20.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct st {
    long long x, y;
    bool sam;
    
    st(long long x, long long y, bool sam) : x(x), y(y), sam(sam) {}
    st() : x(0), y(0), sam(false) {}
} quer[100005];

vector<long long> ls1;
vector<long long> ls2;

int fa[400005];

inline int getf(int s) {
    if (fa[s] < 0) {
        return s;
    }
    int t = s, k;
    while (fa[t] >= 0) {
        t = fa[t];
    }
    while (fa[s] >= 0) {
        k = s;
        s = fa[s];
        fa[k] = t;
    }
    return t;
}

inline void merg(int x, int y) {
    int i = getf(x), j = getf(y);
    if (i == j) return;
    fa[j] = i;
}

int main(int argc, const char * argv[]) {
    int n;
    long long x, y;
    int a, b;
    scanf("%d", &n);
    for (int i = 0; i < 400005; i++) {
        fa[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d %d %d", &x, &y, &a, &b);
        ls1.push_back(x);
        ls2.push_back(y);
        quer[i] = st(x, y, a == b);
    }
    sort(ls1.begin(), ls1.end());
    sort(ls2.begin(), ls2.end());
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (flag) {
            puts("No");
            continue;
        }
        int x = lower_bound(ls1.begin(), ls1.end(), quer[i].x) - ls1.begin();
        int y = lower_bound(ls2.begin(), ls2.end(), quer[i].y) - ls2.begin();
        if (quer[i].sam) {
            if (getf(x) == getf(y+300000)) {
                puts("No");
                flag = true;
                continue;
            }
            merg(x, y+100000);
            merg(x+200000, y+300000);
            puts("Yes");
        } else {
            if (getf(x) == getf(y+100000)) {
                puts("No");
                flag = true;
                continue;
            }
            merg(x, y+300000);
            merg(x+200000, y+100000);
            puts("Yes");
        }
    }
}
