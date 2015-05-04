//
//  main.cpp
//  poj2299
//
//  Created by eycia on 14/12/6.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>

int sq[500005];
int tm[500005];

long long gb(int be, int en) {
    
    if (be + 1 == en) {
        //printf("%d %d %d\n", be, en, 0);
        return 0;
    }
    long long tot = 0;
    int mi = (be + en) / 2;
    tot += gb(be, mi);
    tot += gb(mi, en);
    int i = be, j = mi, k = be;
    while (i < mi && j < en) {
        if (sq[i] <= sq[j]) {
            tm[k++] = sq[i++];
        } else {
            tm[k++] = sq[j++];
            tot+=mi-i;
        }
    }
    while (i < mi) {
        tm[k++] = sq[i++];
    }
    while (j < en) {
        tm[k++] = sq[j++];
    }
    for (int i = be; i < k; i++) {
        sq[i] = tm[i];
    }
    //printf("%d %d %d\n", be, en, tot);
    return tot;
}

int main(int argc, const char * argv[]) {
    int n;
    while (true) {
        scanf("%d", &n);
        if (!n) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &sq[i]);
        }
        printf("%I64d\n", gb(0, n));
    }
}
