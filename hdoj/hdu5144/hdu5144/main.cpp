/*
 start : 2014-12-16 21:48:39 Tuesday
 aced : 2014-12-16 22:50:31 Tuesday
 */

#include <cstdio>
#include <cmath>

#define g 0.1020408163265306
#define g2 0.010412328196584754

int h, v;
int vv;
double hg2;

double f(double v1) {
    double v22 = vv - v1*v1;
    double v12 = v1 * sqrt(v22);
    return v12 * g + sqrt(v12 * v12 * g2 + hg2 * v22);
}

double sanfen() {
    double l = 0, r = v, m, mm;
    while (r - l > 0.00001) {
        m = (l + r) / 2;
        mm = (m + r) / 2;
        if (f(l) > f(r)) {
            r = mm;
        } else {
            l = m;
        }
    }
    return f(l);
}

int main() {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        scanf("%d %d", &h, &v);
        vv = v * v;
        hg2 = 2 * h * g;
        printf("%.2lf\n", sanfen());
    }
}