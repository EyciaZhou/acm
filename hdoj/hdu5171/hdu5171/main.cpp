//
//  main.cpp
//  bc29b
//
//  Created by eycia on 15/2/7.
//  Copyright (c) 2015年 eycia. All rights reserved.
//
#include <iostream>
#include <cstdio>

using namespace std;

#define MOD 10000007
#define ll long long

struct res {
    ll a, b, c, d;
    
    res(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {};
};

res operator* (res &l, res &r) {
    return res((l.a*r.a + l.b*r.c) % MOD,
               (l.a*r.b + l.b*r.d) % MOD,
               (l.c*r.a + l.d*r.c) % MOD,
               (l.c*r.b + l.d*r.d) % MOD);
}

res fib_o = res(0, 1, 1, 1);

res fib(int n) {
    if (n == 1) {
        return fib_o;
    }
    res r = fib(n/2);
    r = r * r;
    if (n % 2 == 1) {
        return r * fib_o;
    }
    return r;
}

int main(int argc, const char * argv[]) {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        
        ll tot = 0;
        
        ll m1 = 0, m2 = 0;
        int te;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &te);
            tot = (tot + te) % MOD;
            if (te >= m1) {
                m2 = m1;
                m1 = te;
            } else {
                if (te > m2) {
                    m2 = te;
                }
            }
        }
        
        tot = (tot + fib(k+3).a * m2) % MOD;
        tot = (tot + fib(k+4).a * m1) % MOD;
        
        tot = tot - m2 - m1 - m1;
        
        while (tot < 0) {
            tot += MOD;
        }
        
        cout << tot << endl;
    }
}
