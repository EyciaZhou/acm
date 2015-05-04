//
//  main.cpp
//  hdu5101
//
//  Created by eycia on 14/11/24.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int l[1005];
long long mm[1005][105];
long long m2[100005];

long long k;

inline long long ani(long long *d, int l) {
    int j = l - 1;
    int t = 0;
    long long tot = 0;
    for (int i = 0; i < l; i++) {
        while (j >= 0 && j > i && d[i] + d[j] > k) {
            j--;
            t++;
        }
        while (j < i) {
            j++;
            t--;
        }
        tot += t;
    }
    return tot;
}

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    int n, tl;
    while (ff--) {
        memset(mm, 0, sizeof(mm));
        memset(m2, 0, sizeof(m2));
        scanf("%d %I64d", &n, &k);
        tl = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &l[i]);
            for (int j = 0; j < l[i]; j++) {
                scanf("%I64d", &mm[i][j]);
                m2[tl++] = mm[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            sort(mm[i], mm[i] + l[i]);
        }
        
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            tot += ani(mm[i], l[i]);
        }
        sort(m2, m2+tl);
        tot = ani(m2, tl) - tot;
        printf("%I64d\n", tot);
    }
}
