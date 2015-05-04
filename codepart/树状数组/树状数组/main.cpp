//
//  main.cpp
//  树状数组
//
//  Created by eycia on 14/10/22.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

struct BIT {
#define BIT_MAX_LEN 100005
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
    
    inline void modify(int index, BIT_  TYPE delta) {
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

struct BIT2D {
#define BIT_MAX_LEN_N 100005
#define BIT_MAX_LEN_M 100005
    typedef int BIT_TYPE;
    
    BIT_TYPE c[BIT_MAX_LEN_N][BIT_MAX_LEN_M];
    int len_n;
    int len_m;
    
    inline int lowbit(int x) {
        return x & (-x);
    }
    
    inline void build(int n, int m) {
        memset(c, 0, sizeof(c));
        len_n = n;
        len_m = m;
    }
    
    inline void modify(int i_n, int i_m, BIT_TYPE delta) {
        for (int i = i_n; i <= len_n; i += lowbit(i)) {
            for (int j = i_m; j <= len_m; j += lowbit(j)) {
                c[i][j] += delta;
            }
        }
    }
    
    inline BIT_TYPE sum(int i_n, int i_m) {
        int ans = 0;
        for (int i = i_n; i > 0; i -= lowbit(i)) {
            for (int j = i_m; j > 0; j -= lowbit(j)) {
                ans += c[i][j];
            }
        }
        return ans;
    }
    
    inline BIT_TYPE sum(int i_n1, int i_m1, int i_n2, int i_m2) {
        if (i_n1 > i_n2) {
            swap(i_n1, i_n2);
            swap(i_m1, i_m2);
        }
        if (i_n1 == 0 && i_m1 == 0) {
            return sum(i_n2, i_m2);
        }
        return sum(i_n2, i_m2) - sum(i_n1, i_m2) - sum(i_n2, i_m1) + sum(i_n1, i_m1);
    }
    
#undef BIT_MAX_LEN_N
#undef BIT_MAX_LEN_M
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
