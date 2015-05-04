//
//  main.cpp
//  poj1195
//
//  Created by eycia on 14/10/23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct BIT2D {
#define BIT_MAX_LEN_N 1030
#define BIT_MAX_LEN_M 1030
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
        //]
        int ans = 0;
        for (int i = i_n; i > 0; i -= lowbit(i)) {
            for (int j = i_m; j > 0; j -= lowbit(j)) {
                ans += c[i][j];
            }
        }
        return ans;
    }
    
    inline BIT_TYPE sum(int i_n1, int i_m1, int i_n2, int i_m2) {
        //(]
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
    BIT2D bit2d;
    int o, p1, p2, p3, p4;
    
    scanf("%d %d", &o, &p1);
    //cin >> o >> p1;
    
    bit2d.build(p1 + 1, p1 + 1);
    while (true) {
        scanf("%d", &o);
        //cin >> o;
        switch (o) {
            case 1:
                scanf("%d %d %d", &p1, &p2, &p3);
                //cin >> p1 >> p2 >> p3;
                bit2d.modify(p1 + 1, p2 + 1, p3);
                break;
            case 2:
                scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
                //cin >> p1 >> p2 >> p3 >> p4;
                printf("%d\n", bit2d.sum(p1, p2, p3 + 1, p4 + 1));
                //cout << bit2d.sum(p1, p2, p3 + 1, p4 + 1) << endl;
                break;
            case 3:
                return 0;
        }
    }
}
