//
//  main.cpp
//  hdu1541
//
//  Created by eycia on 14/10/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>

struct BIT {
#define BIT_MAX_LEN 32010
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
    
#undef BIT_MAX_LEN
};

int c[15005];

int main(int argc, const char * argv[]) {
    BIT bit;
    int n;
    while (scanf("%d", &n)!=EOF) {
        memset(c, 0, sizeof(c));
        int x, y;
        bit.build(32005);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            x++;
            c[bit.sum(x)]++;
            bit.modify(x, 1);
        }
        for (int i = 0; i < n; i++) {
            printf("%d\n", c[i]);
        }
    }
}
