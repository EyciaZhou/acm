//
//  main.cpp
//  hdu5130
//
//  Created by eycia on 14/12/21.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

struct vec;
struct po;

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
    vec vertical() {return vec(-y, x);}
    vec unit();
};

struct cir {
    po o;
    double r;
    cir(po o, double r) : o(o), r(r) {}
    bool insi(po &p);
    void meet(po &p1, po &p2, po &r1, po &r2);
};

double pi = acos(-1.0);
double eps = 1e-8;
po operator+(const po &p, const vec &v) {return po(p.x + v.x, p.y + v.y);}
po operator-(const po &p, const vec &v) {return po(p.x - v.x, p.y - v.y);}
vec operator*(const vec &v, double b) {return vec(v.x * b, v.y * b);}
double operator*(const vec &v1, const vec &v2) {return v1.x * v2.x + v1.y * v2.y;}
vec vec::unit() {return *this * (1/lens());}
double distant(po p1, po p2) {return vec(p1, p2).lens();}
double distant(po p, po v1, po v2) {if (fabs(vec(v1, v2).lens()) < eps) return distant(p, v1); return fabs(vec(p, v1) * vec(v1, v2).vertical().unit());}
double cross(vec v1, vec v2){return v1.x * v2.y - v2.x * v1.y;}
double vec2deg(vec v1, vec v2) {return acos(max(min(v1 * v2 / v1.lens() / v2.lens(), 1.0), -1.0));}
double neg(double n) {if (n > eps) return 1.0; else if (n < -eps) return -1.0; else return 0.0;}
bool cir::insi(po &p) {return (distant(o, p) < r);}
void cir::meet(po &p1, po &p2, po &r1, po &r2) {
    vec a = vec(p1, p2).vertical().unit() * distant(o, p1, p2);a = a * neg(a * vec(o, p1));vec b = vec(p1, p2).unit() * sqrt(max(r * r - a * a, 0.0));r1=o+a-b;r2=o+a+b;}//r1左侧（p1侧）

po pos[505];

double case1(cir &c, po &p1, po &p2) {
    if (vec(p1, p2).lens() < eps) return 0;
    return cross(vec(c.o, p1), vec(c.o, p2)) * 0.5;
}

double case2(cir &c, po &p1, po &p2) {
    if (vec(p1, p2).lens() < eps) return 0;
    if (fabs(vec(c.o, p1).lens()) < eps) return 0;
    if (fabs(vec(c.o, p2).lens()) < eps) return 0;
    return neg(cross(vec(c.o, p1), vec(c.o, p2))) * vec2deg(vec(c.o, p1), vec(c.o, p2)) * 0.5 * c.r * c.r;
}

double solve(cir &c, po &p1, po &p2) {
    if (vec(p1, p2).lens() < eps) return 0;
    if (c.insi(p1) && c.insi(p2)) {
        return case1(c, p1, p2);
    }
    po r1, r2;
    c.meet(p1, p2, r1, r2);
    if (c.insi(p1)) {
        return case1(c, p1, r2) + case2(c, r2, p2);
    }
    if (c.insi(p2)) {
        return case2(c, p1, r1) + case1(c, r1, p2);
    }
    if (distant(c.o, p1, p2) < c.r) {
        if (neg(vec(c.o, p1) * vec(p1, p2)) == neg(vec(c.o, p2) * vec(p1, p2))) {
            return case2(c, p1, p2);
        }
        return case2(c, p1, r1) + case1(c, r1, r2) + case2(c, r2, p2);
    } else {
        return case2(c, p1, p2);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    double k;
    po A, B;
    int ff = 0;
    while (scanf("%d %lf", &n, &k) != EOF) {
        ff++;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &pos[i].x, &pos[i].y);
        }
        pos[n] = pos[0];
        scanf("%lf %lf", &A.x, &A.y);
        scanf("%lf %lf", &B.x, &B.y);
        
        vec AB(B, A), R = AB * (k / (1 - k * k));
        vec d1 = AB * (k / (1 + k));
        
        cir C(B + d1 - R, R.lens());
        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += solve(C, pos[i], pos[i+1]);
        }
        printf("Case %d: %.10lf\n", ff, fabs(ans));
    }
}