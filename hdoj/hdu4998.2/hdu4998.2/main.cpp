//
//  main.cpp
//  hdu4998.2
//
//  Created by eycia on 9/6/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

#define rep(i,t) for(int (i)=0;i<t;i++)

//const part
double pi = acos(-1.0);
double eps = 1e-9;
double deg2ang = 360/pi;
double ang2deg = pi/360;

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

struct cir {
    po o;
    double r;
    cir(po o, double r) : o(o), r(r) {}
    bool insi(po &p);   //judge if p inside the cir
    void meet(po &p1, po &p2, po &r1, po &r2); //meet p1, p2 returns r1 r2
};

struct mat3x3 {
    double a, b, c;
    double d, e, f;
    double g, h, i;
    inline double& operator[](size_t idx) {return ((double *)this)[idx];};
    inline const double& operator[](size_t idx) const {return ((double *)this)[idx];};
#define dd double
    mat3x3(dd a, dd b, dd c, dd d, dd e, dd f, dd g, dd h, dd i) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}
    mat3x3() {for (int i = 0; i < 9; i++) this->operator[](i) = 0.0;}
#undef dd
    void pr(){rep(i, 3) {rep(j, 3) cout << this->operator[](i*3+j) << " "; cout << endl;}cout << endl;}
    void fix(){
        rep(i,9) if (fabs((*this)[i]) < eps) (*this)[i] = 0;
    }
};

//operator of base part
po inline operator+(const po &p, const vec &v) {return po(p.x + v.x, p.y + v.y);}
po inline operator-(const po &p, const vec &v) {return po(p.x - v.x, p.y - v.y);}
vec inline operator*(const vec &v, double b) {return vec(v.x * b, v.y * b);}
double inline operator*(const vec &v1, const vec &v2) {return v1.x * v2.x + v1.y * v2.y;}
double inline operator^(const vec &v1, const vec &v2) {return v1.x * v2.y - v2.x * v1.y;}
mat3x3 inline operator*(const mat3x3 &l, const mat3x3 &r) {mat3x3 tmp;rep(i, 3) rep(j, 3) rep(k, 3) tmp[i*3+j] += l[i*3+k]*r[k*3+j];return tmp;}
po inline operator*(const po &p, const mat3x3 &m) {double t1=0, t2=0;rep(i, 3) {t1+=p.x*m[i*3];t2+=p.y*m[i*3+1];}return po(t1, t2);}

//etc part
double inline distant(po p1, po p2) {return vec(p1, p2).lens();}
double inline distant(po p, po v1, po v2) {if (fabs(vec(v1, v2).lens()) < eps) return distant(p, v1); return fabs(vec(p, v1) * vec(v1, v2).vertical().unit());}
double vec2deg(vec v1, vec v2) {return acos(max(min(v1 * v2 / v1.lens() / v2.lens(), 1.0), -1.0));} //return the deg of two vector
double neg(double n) {if (n > eps) return 1.0; else if (n < -eps) return -1.0; else return 0.0;}
inline double safe(double a) {return (a != a) ? 0 : a;}
inline double to2pi(double a) {while (a < 0) a+=2*pi;while (a >= 2*pi) a-=2*pi;return a;}

//this part shound with base type part
vec vec::unit() {return *this * (1/lens());}
bool cir::insi(po &p) {return (distant(o, p) < r);}
void cir::meet(po &p1, po &p2, po &r1, po &r2) {
    vec a = vec(p1, p2).vertical().unit() * distant(o, p1, p2);a = a * neg(a * vec(o, p1));vec b = vec(p1, p2).unit() * sqrt(max(r * r - a * a, 0.0));r1=o+a-b;r2=o+a+b;}//r1左侧（p1侧）

//transform part
#define move(tx, ty) mat3x3(1, 0, 0, 0, 1, 0, (tx), (ty), 1)
#define scale(sx,sy) mat3x3((sx), 0, 0, 0, (sy), 0, 0, 0, 1)
#define rotaCounterClockwise(theta) mat3x3(cos(theta), sin(theta), 0, -sin(theta), cos(theta), 0, 0, 0, 1)
#define rotaClockwise(theta) rotaCounterClockwise(-theta)
#define rota(theta) rotaCounterClockwise(theta)
#define withPo(expr, po) move(-po.x, -po.y)*(expr)*move(po.x, po.y)
#define rotaWithPo(theta, po) withPo(rota(theta), po)
#define scaleWithPo(sx, sy, po) withPo(scale(sx, sy), po)
#define symABx   mat3x3 ( 1,0,0, 0,-1,0,0,0,1)
#define symABy   mat3x3 (-1,0,0, 0, 1,0,0,0,1)
#define symABo   mat3x3 (-1,0,0, 0,-1,0,0,0,1)
#define symABxy  mat3x3 (0, 1,0, 1, 0,0,0,0,1)
#define symABxfy mat3x3 (0,-1,0,-1, 0,0,0,0,1)
#define one      mat3x3 (1, 0,0, 0, 1,0,0,0,1)

#define mr1 mat[0]
#define mr2 mat[1]
#define mr3 mat[3]
#define mr4 mat[4]
#define ma1 mat[6]
#define ma2 mat[7]

//矩阵反演 当矩阵只经过旋转平移时
#define re_theta atan2(mr2,mr1)
#define re_mx (-mr2*ma2-ma1*(mr1-1))/((mr1-1)*(mr1-1)+mr2*mr2)
#define re_my ( mr2*ma1-ma2*(mr1-1))/((mr1-1)*(mr1-1)+mr2*mr2)


int main(int argc, const char * argv[]) {
    int t, k;
    double x, y, p;
    cin >> t;
    while (t--) {
        cin >> k;
        mat3x3 mat = one;
        while (k--) {
            cin >> x >> y >> p;
            mat = mat * rotaWithPo(p, po(x, y));
            mat.fix();
        }
        fixed(cout);
        cout << setprecision(10) << safe(re_mx) << " " << safe(re_my) << " " << to2pi(safe(re_theta)) << endl;
    }
}
