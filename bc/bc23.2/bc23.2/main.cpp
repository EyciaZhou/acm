//
//  main.cpp
//  bc23.2
//
//  Created by eycia on 14/12/20.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int a[50020];
int c[50020];

struct BIT {
#define BIT_MAX_LEN 50020
    typedef int BIT_TYPE;
    
    BIT_TYPE c[BIT_MAX_LEN];
    int len;
    
    inline int lowbit(int x) {
        return x & (-x);
    }
    
    inline void build(int l) {
        memset(c, 0, sizeof(c));
        len = l;
    }
    
    inline void modify(int index, BIT_TYPE delta) {
        for (int i = index; i <= len; i += lowbit(i)) {
            c[i] += delta;
        }
    }
    
    inline BIT_TYPE sum(int k) {
        int ans = 0;
        for (int i = k; i > 0; i -= lowbit(i)) {
            ans += c[i];
        }
        return ans;
    }
    
    inline BIT_TYPE sum(int s, int e) {
        //[s, e]
        if (s > e) {
            swap(s, e);
        }
        if (s == 0) {
            return sum(e);
        }
        return sum(e) - sum(s - 1);
    }
    
#undef BIT_MAX_LEN
};

BIT bit1;
BIT bit2;

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n;
        scanf("%d", &n);
        bit1.build(n+9);
        bit2.build(n+9);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        bit1.modify(a[0], 1);
        for (int i = 1; i < n; i++) {
            c[i] = bit1.sum(a[i]);
            bit1.modify(a[i], 1);
        }
        
        for (int i = 1; i < n; i++) {
            c[i] += c[i-1];
        }
        
        long long tot = 0;
        bit2.modify(a[n-1], 1);
        for (int i = n - 2; i >= 2; i--) {
            tot += (long long)bit2.sum(a[i], n+5) * (long long)c[i-1];
            bit2.modify(a[i], 1);
        }
        printf("%lld\n", tot);
    }
}
