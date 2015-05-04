//
//  main.cpp
//  poj2777
//
//  Created by eycia on 14/10/24.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <cstring>

inline int getone(int value)
{
    value = (value & 0x55555555) + ((value >> 1) & 0x55555555);
    value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
    value = (value & 0x0F0F0F0F) + ((value >> 4) & 0x0F0F0F0F);
    value = (value & 0x00FF00FF) + ((value >> 8) & 0x00FF00FF);
    value = (value & 0x0000FFFF) + ((value >> 16) & 0x0000FFFF);
    return value;
}

#define ST_MAX_LEN 270000
    struct OneNode {
        int now;
        bool la;
        int ml;
        int mr;
    };
    int len;
    int len2;
    OneNode nodes[ST_MAX_LEN];
    
    void modify(int point, int s, int e, int v) {
        if (point >= len) {
            nodes[point].now = v;
            return;
        }
        
        OneNode& n = nodes[point];
        OneNode& lc = nodes[point << 1];
        OneNode& rc = nodes[point << 1 | 1];
        
        if (n.la && !(v ^ n.now)) {
            return;
        }
        
        if (n.ml == s && n.mr == e) {
            n.now = v;
            n.la = true;
            return;
        }
        
        if (n.la) {
            lc.la = rc.la = true;
            lc.now = rc.now = n.now;
            n.la = false;
        }
        
        if (s >= rc.ml) {
            modify(point << 1 | 1, s, e, v);
        } else if (e <= lc.mr) {
            modify(point << 1, s, e, v);
        } else {
            modify(point << 1, s, lc.mr, v);
            modify(point << 1 | 1, rc.ml, e, v);
        }
        
        n.now = lc.now | rc.now;
    }

    int getsum(int point, int s, int e) {
        if (point >= len) {
            return nodes[point].now;
        }
        
        if (nodes[point].la) {
            return nodes[point].now;
        }
        
        OneNode& n = nodes[point];
        OneNode& lc = nodes[point << 1];
        OneNode& rc = nodes[point << 1 | 1];
        
        if (n.la) {
            lc.la = rc.la = true;
            lc.now = rc.now = n.now;
            n.la = false;
        }
        
        if (n.ml == s && n.mr == e) {
            return n.now;
        }
        if (s >= rc.ml) {
            return getsum(point << 1 | 1, s, e);
        }else if (e <= lc.mr) {
            return getsum(point << 1, s, e);
        } else {
            return getsum(point << 1, s, lc.mr) | getsum(point << 1 | 1, rc.ml, e);
        }
    }
    
    void build(int l, int l2) {
        len = l;
        len2 = l2;
        for (int i = len; i < len + len2; i++) {
            nodes[i].now = 1;
            nodes[i].ml = nodes[i].mr = i - len + 1;
        }
        
        for (int i = len+len2; i < len*2; i++) {
            nodes[i].now = 0;
            nodes[i].ml = nodes[i].mr = i - len + 1;
        }
        
        for (int i = len - 1; i >= 1; i--) {
            nodes[i].now = nodes[i*2].now | nodes[i*2+1].now;
            nodes[i].ml = nodes[i*2].ml;
            nodes[i].mr = nodes[i*2+1].mr;
        }
    }
#undef ST_MAX_LEN

int main(int argc, const char * argv[]) {
    int le, ts, os;
    char c[10];
    int s, e, v, t;
    scanf("%d%d%d", &le, &ts, &os);
    build(1 << (int(log(le + 0.0) / log(2.0) - 0.00000001) + 1), le);
    for (int i = 0; i < os; i++) {
        scanf("%s%d%d", c, &s, &e);
        if (c[0] == 'P') {
            if (s > e) {
                t = s;
                s = e;
                e = t;
            }
            int r = getsum(1, s, e);
            printf("%d\n", getone(r));
        } else {
            scanf("%d", &v);
            if (s > e) {
                t = s;
                s = e;
                e = t;
            }
            modify(1, s, e, (1 << (v-1)));
        }
    }
    return 0;
}
