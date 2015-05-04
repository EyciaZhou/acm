//
//  main.cpp
//  hdu1166
//
//  Created by eycia on 14/10/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct BIT {
#define BIT_MAX_LEN 500005
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

int main(int argc, const char * argv[]) {
    int ff;
    int v1, v2, t;
    char query[20];
    BIT bit;
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        printf("Case %d:\n", tt);
        int n;
        scanf("%d", &n);
        bit.build(n+1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &t);
            bit.modify(i, t);
        }
        bool fl = true;
        while (fl) {
            scanf("%s", query);
            switch (query[0]) {
                case 'Q':
                    scanf("%d %d", &v1, &v2);
                    printf("%d\n", bit.sum(v1, v2));
                    break;
                case 'A':
                    scanf("%d %d", &v1, &v2);
                    bit.modify(v1, v2);
                    break;
                case 'S':
                    scanf("%d %d", &v1, &v2);
                    bit.modify(v1, -v2);
                    break;
                case 'E':
                    fl = false;
                    break;
            }
        }
    }
}