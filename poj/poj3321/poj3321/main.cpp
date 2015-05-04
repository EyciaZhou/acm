//
//  main.cpp
//  poj3321
//
//  Created by eycia on 14/10/22.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;

int mm[100005][100];
int len[100005];
int now[100005];
int start[100005];
bool apple[100005];

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

void dfs() {
    int index = 1;
    stack<int> st;
    stack<int> st2;
    st.push(1);
    st2.push(0);
    while (!st.empty()) {
        int &k = st.top();
        int &p = st2.top();
        
        if (p == len[k]) {
            st.pop();
            st2.pop();
            now[k] = index++;
            if (len[k] == 0) {
                start[k] = now[k];
            } else {
                start[k] = start[mm[k][0]];
            }
        } else {
            st.push(mm[k][p]);
            st2.push(0);
            p++;
        }
    }
}

int main(int argc, const char * argv[]) {
    BIT bit;
    int n, m, t1, t2, o;
    char c;
    scanf("%d", &n);
    bit.build(n + 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &t1, &t2);
        mm[t1][len[t1]++] = t2;
    }
    for (int i = 1; i <= n; i++) {
        bit.modify(i, 1);
        apple[i] = true;
    }
    dfs();
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        getchar();
        scanf("%c %d", &c, &o);
        if (c == 'Q') {
            printf("%d\n", bit.sum(start[o], now[o]));
        } else {
            if (apple[o]) {
                bit.modify(now[o], -1);
            } else {
                bit.modify(now[o], 1);
            }
            apple[o] = !apple[o];
        }
    }
}
