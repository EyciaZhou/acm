//
//  main.cpp
//  hdu1856
//
//  Created by eycia on 14-9-21.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int fa[10000001];
int tot[10000001];

inline int getf(int s) {
    if (fa[s] == s) {
        return s;
    }
    int t = s;
    while (fa[t] != t) {
        t = fa[t];
    }
    fa[s] = t;
    while (fa[s] != s) {
        s = fa[s];
        fa[s] = t;
    }
    return t;
}

int main(int argc, const char * argv[]) {
    int n, a, b;
    while (cin >> n) {
        if (n == 0) {
            printf("%d\n", 1);
            continue;
        }
        for (int i = 1; i <= 10000000; i++) {
            fa[i] = i;
            tot[i] = 0;
        }
        int mm = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            if (getf(a) != getf(b)) {
                fa[fa[a]] = fa[b];
            }
            if (a > mm) {
                mm = a;
            }
            if (b > mm) {
                mm = b;
            }
        }
        for (int i = 1; i <= mm; i++) {
            getf(i);
            tot[fa[i]]++;
        }
        int max = 0;
        for (int i = 1; i <= mm; i++) {
            if (tot[i] > max) {
                max = tot[i];
            }
        }
        printf("%d\n", max);
    }
}
