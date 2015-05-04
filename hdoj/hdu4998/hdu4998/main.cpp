//
//  main.cpp
//  f1002
//
//  Created by eycia on 14-9-13.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Rotate(double x1, double y1, double x2, double y2, double alpha, double& r1, double& r2) {
    r1 = (x1 - x2) * cos(alpha) - (y1 - y2) * sin(alpha) + x2;
    r2 = (x1 - x2) * sin(alpha) + (y1 - y2) * cos(alpha) + y2;
}

double point(double x1, double y1, double x2, double y2, double a1, double b1, double a2, double b2) {
    return (x1 - x2) * (a1 - a2) + (y1 - y2) * (b1 - b2);
}

double len(double x, double y, double a, double b) {
    return (x - a) * (x - a) + (y - b) * (y - b);
}

int main(int argc, const char * argv[]) {
    int ff;
    double pi = 3.1415926535897932384626433832795028841971693993;
    double x, y, p;
    double xx1, yy1, xx2, yy2, aa1, bb1, aa2, bb2, r1, r2, t;
    cin >> ff;
    while (ff--) {
        int n;
        cin >> n;
        double x1 = 1.23, y1 = 2.34;
        double a1 = 3.45, b1 = 4.56;
        double x2, y2;
        double a2, b2;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> p;
            Rotate(x1, y1, x, y, p, x2, y2);
            Rotate(a1, b1, x, y, p, a2, b2);
            x1 = x2;
            y1 = y2;
            a1 = a2;
            b1 = b2;
        }
        
        xx1 = (x1 + 1.23) / 2;
        yy1 = (y1 + 2.34) / 2;
        xx2 = xx1 + y1 - 2.34;
        yy2 = yy1 - x1 + 1.23;
        
        aa1 = (a1 + 3.45) / 2;
        bb1 = (b1 + 4.56) / 2;
        aa2 = aa1 + b1 - 4.56;
        bb2 = bb1 - a1 + 3.45;
        
        r1 = xx1;
        r2 = yy1;
        
        t = ((xx1-aa1)*(bb2-bb1)-(yy1-bb1)*(aa2-aa1)) / ((xx1-xx2)*(bb2-bb1)-(yy1-yy2)*(aa2-aa1));
        
        r1 += (xx2-xx1)*t;
        if ((r1 < 0 && r1 > -0.00000000001) || (r1 != r1)) {
            r1 = 0;
        }
        r2 += (yy2-yy1)*t;
        if ((r2 < 0 && r2 > -0.00000000001) || (r2 != r2)) {
            r2 = 0;
        }
        
        cout << fixed <<  setprecision(10) << r1 << " " <<  r2 << " ";
        if ((x1 - a1) * (1.23 - 3.45) - (2.34 - 4.56) * (y1 - b1) > 0) {
            cout << fixed <<  setprecision(10) << 2 * pi -acos(point(x1, y1, a1, b1, 1.23, 2.34, 3.45, 4.56) / len(1.23, 2.34, 3.45, 4.56)) << endl;
        } else {
            cout << acos(point(x1, y1, a1, b1, 1.23, 2.34, 3.45, 4.56) / len(1.23, 2.34, 3.45, 4.56)) << endl;
        }
    }
    return 0;
}
