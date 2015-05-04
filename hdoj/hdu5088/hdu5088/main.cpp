//
//  main.cpp
//  hdu5088
//
//  Created by eycia on 14/11/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//
 /*
 #include <iostream>
 #include <bitset>
 */
#include <cstdio>
#include <algorithm>
using namespace std;

long long a[1005];
/*
 void pb(long long i) {
 bitset<64> te(i);
 cout << te.to_string() << endl;
 }
 */
int main(int argc, const char * argv[]) {
    int ff, n;
    scanf("%d", &ff);
    while (ff--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%I64d", &a[i]);
        }
        
        if (n > 40) {
            printf("Yes\n");
            continue;
        }
        
        for (int k = 45; k >= 0; k--) {
            long long te = ((long long)(1) << k);
            long long kk = ~(te - 1);
            int j = -1;
            for (int i = 0; i < n; i++) {
                if (((a[i] & te) == (a[i] & kk)) && ((a[i] & te) == te)) {
                    j = i;
                    break;
                }
            }
            if (j != -1) {
                for (int i = 0; i < n; i++) {
                    if (i != j) {
                        if (((a[i] & te) == (a[i] & kk)) && ((a[i] & te) == te)) {
                            a[i] = a[i] ^ a[j];
                        }
                    }
                }
            }
        }
        sort(a, a+n);
        if (a[0] == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
