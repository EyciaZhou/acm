//
//  main.cpp
//  poj1696
//
//  Created by eycia on 9/6/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

#define pi acos(-1.0)
#define eps 1e-9

//base type part
struct po {
    double x, y;
    po() : x(0), y(0) {}
    po(double xx, double yy) : x(xx), y(yy) {}
};

struct vec {
    double x, y;
    vec() : x(0), y(0) {}
    vec(double xx, double yy) : x(xx), y(yy) {}
    vec(po from, po to) : x(to.x - from.x), y(to.y - from.y){}
    double lens() {return sqrt(x * x + y * y);}
    vec vertical() {return vec(-y, x);} //垂直
    vec unit(); //单位
};

double inline operator*(const vec &v1, const vec &v2) {return v1.x * v2.x + v1.y * v2.y;}
double inline operator^(const vec &v1, const vec &v2) {return v1.x * v2.y - v2.x * v1.y;}

double vec2deg(vec v1, vec v2) {return acos(max(min(v1 * v2 / v1.lens() / v2.lens(), 1.0), -1.0));}

int no[55];
vector<po > ps;
bool v[55];

int main(int argc, const char * argv[]) {
    int t, nn, xx, yy;
    cin >> t;
    while (t--) {
        int n;
        memset(v, false, sizeof(v));
        ps.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nn >> xx >> yy;
            no[i] = nn;
            ps.push_back(po(xx, yy));
        }
        
        cout << n << " ";
        po tmp(1000, 1000);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (ps[i].y < tmp.y || (ps[i].y == tmp.y && ps[i].x < tmp.x)) {
                tmp = ps[i];
                k = i;
            }
        }
        cout << no[k] << " ";
        v[k] = true;
        vec v1(po(0, tmp.y), tmp);
        for (int ff = 0; ff < n-1; ff++) {
            double ang = 3*pi;
            int tk = 0;
            for (int i = 0; i < n; i++) {
                if (!v[i]) {
                    vec v2(ps[k], ps[i]);
                    double tang = vec2deg(v1, v2);
                    if (tang < ang || (fabs(tang-ang) < eps && vec(ps[k], ps[tk]).lens() > vec(ps[k], ps[i]).lens())) {
                        ang = tang;
                        tk = i;
                    }
                }
            }
            v[tk] = true;
            cout << no[tk] << " ";
            v1 = vec(ps[k], ps[tk]);
            k = tk;
        }
        cout << endl;
    }
}
