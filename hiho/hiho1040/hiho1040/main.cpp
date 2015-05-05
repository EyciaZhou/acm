//
//  main.cpp
//  hiho1040
//
//  Created by eycia on 5/5/15.
//  Copyright (c) 2015 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <map>
#include <cstdio>
using namespace std;

struct vec;
struct po;

#define ll long long

struct po {
    ll x, y;
    po() : x(0), y(0) {}
    po(ll xx, ll yy) : x(xx), y(yy) {}
};

struct vec {
    ll x, y;
    vec() : x(0), y(0) {}
    vec(ll xx, ll yy) : x(xx), y(yy) {}
    vec(po from, po to) : x(to.x - from.x), y(to.y - from.y) {}
    long long lens2() {return x * x + y * y;}
};

ll operator*(const vec &v1, const vec &v2) {return v1.x * v2.x + v1.y * v2.y;}

vec v[4];

map<pair<int, int>, bool> ps;

int main() {
    int t;
    int x1, y1, x2, y2;
    cin >>t;
    for (int ff = 1; ff <= t; ff++) {
        ps.clear();
        for (int i = 0; i < 4; i++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            v[i] = vec(po(x1, y1), po(x2, y2));
            ps[{x1, y1}] = true;
            ps[{x2, y2}] = true;
        }
        if (ps.size() > 4 || ps.size() < 4) {
            cout << "NO" << endl;
            continue;
        }
        int tot = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    if (v[i] * v[j] == 0) {
                        tot++;
                    }
                }
            }
        }
        if (tot == 8) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
