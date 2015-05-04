//
//  main.cpp
//  c
//
//  Created by Serx on 14/12/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

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
double eps = 1e-9;
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

int main(int argc, const char * argv[]) {
    po home, school;
    cin >> home.x >> home.y;
    cin >> school.x >> school.y;
    int n;
    cin >> n;
    double a, b, c;
    int tot = 0;
    while (n--) {
        cin >> a >> b >> c;
        po p1, p2;
        if (abs(a) < eps) {
            p1 = po(-100, -c/b);
            p2 = po(100, -c/b);
        } else if (abs(b) < eps) {
            p1 = po(-c/a, -100);
            p2 = po(-c/a, 100);
        } else {
            p1 = po(-100, -c/b+100*a/b);
            p2 = po(100, -c/b-100*a/b);
        }
        if ((cross(vec(home, p1), vec(home, p2)) > 0) ^ (cross(vec(school, p1), vec(school, p2)) > 0)) {
            tot++;
        }
    }
    cout << tot << endl;
}