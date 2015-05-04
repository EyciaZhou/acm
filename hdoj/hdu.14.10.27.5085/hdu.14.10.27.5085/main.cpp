//
//  main.cpp
//  hdu.14.10.27.5085
//
//  Created by eycia on 14/10/27.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>

typedef long long ll;
#define hash_len 20007

ll po[10][16];
int ten[20];

int k;
ll s;

ll boo[16][1000];

inline ll boom(ll n) {
    return boo[k][n / 1000] + boo[k][n % 1000];
}

bool tt[6][16];

ll hh[6][16][hash_len];
int vv[6][16][hash_len];
bool ii[6][16][hash_len];

inline int hash2(int a, int b, ll k2) {
    int p = k2 % hash_len;
    while (ii[a][b][p] && hh[a][b][p] != k2) {
        p = (p + 1) % hash_len;
    }
    return p % hash_len;
}

int get(int n, int m) {
    int hr = int(log(m+0.0) / log(10.0) + 0.99999) / 2;
    int hhll = ten[hr];
    
    int result = 0;
    
    if (n / hhll == m / hhll) {
        ll h1 = boom(n / hhll);
        for (int i = n % hhll; i <= m % hhll; i++) {
            if (h1 + boom(i) == s) {
                result ++;
            }
        }
        return result;
    }
    
    if (!tt[hr][k]) {
        tt[hr][k] = true;
        for (ll i = 0; i < hhll; i++) {
            ll re = boom(i);
            int h = hash2(hr, k, re);
            hh[hr][k][h] = re;
            ii[hr][k][h] = true;
            vv[hr][k][h] = vv[hr][k][h] + 1;
        }
    }
    
    for (int i = n / hhll + 1; i < m / hhll; i++) {
        ll re = boom(i);
        if (re > s) {
            continue;
        }
        int h = hash2(hr, k, s - re);
        if (ii[hr][k][h]) {
            result += vv[hr][k][h];
        }
    }
    ll h1 = boom(n / hhll);
    for (int i = n % hhll; i < hhll; i++) {
        if (h1 + boom(i) == s) {
            result ++;
        }
    }
    ll h2 = boom(m/hhll);
    for (int i = 0; i <= m % hhll; i++) {
        if (h2 + boom(i) == s) {
            result ++;
        }
    }
    return result;
}

void pr() {
    ten[0] = 1;
    for (int i = 1; i < 20; i++) {
        ten[i] = ten[i - 1] * 10;
    }
    for (int i = 0; i < 10; i++) {
        po[i][0] = 1;
    }
    for (int k = 1; k <= 15; k++) {
        for (int i = 0; i < 10; i++) {
            po[i][k] = po[i][k-1] * i;
        }
    }
    for (int k = 1; k <= 15; k++) {
        for (int i = 0; i < 1000; i++) {
            int p = i;
            ll result = 0;
            while (p > 0) {
                result += po[p%10][k];
                p/=10;
            }
            boo[k][i] = result;
        }
    }
}

int main(int argc, const char * argv[]) {
    pr();
    int a, b;
    memset(tt, false, sizeof(tt));
    memset(hh, 0, sizeof(hh));
    memset(vv, 0, sizeof(vv));
    memset(ii, false, sizeof(ii));
    while (scanf("%d %d %d %lld", &a, &b, &k, &s) != EOF) {
        printf("%d\n", get(a, b));
    }
}