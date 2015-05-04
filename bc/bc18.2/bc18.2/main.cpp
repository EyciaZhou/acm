//
//  main.cpp
//  bc18.2
//
//  Created by eycia on 14/11/15.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

double a, b, c, d;

inline double f(double x) {
    double aa = abs(a * x * x * x + b * x * x + c * x + d);
    //cout << x << " " << aa << endl;
    return aa;
}

inline double ll() {
    double aa = 3 * a, bb = 2 * b, cc = c;
    return (-bb + sqrt(bb * bb - 4 * aa * cc)) / (2 * aa);
}

inline double rr() {
    double aa = 3 * a, bb = 2 * b, cc = c;
    return (-bb - sqrt(bb * bb - 4 * aa * cc)) / (2 * aa);
}

int main(int argc, const char * argv[]) {
    double l, r;
    while (cin >> a >> b >> c >> d >> l >> r) {
        double result = 0;
        double aa = 3 * a, bb = 2 * b, cc = c;
        double x;
        
        if (abs(a) < 0.0000001) {
            if (abs(b) < 0.0000001) {
                x = l;
                if (x <= r && x >= l) {
                    double ans = f(x);
                    if (ans > result) {
                        result = ans;
                    }
                }
                x = r;
                if (x <= r && x >= l) {
                    double ans = f(x);
                    if (ans > result) {
                        result = ans;
                    }
                }
            } else {
            
            x = -c / (2 * b);
            if (x <= r && x >= l) {
                double ans = f(x);
                if (ans > result) {
                    result = ans;
                }
            }
            x = l;
            if (x <= r && x >= l) {
                double ans = f(x);
                if (ans > result) {
                    result = ans;
                }
            }
            x = r;
            if (x <= r && x >= l) {
                double ans = f(x);
                if (ans > result) {
                    result = ans;
                }
            }
            }
        } else {
        
        if (bb * bb - 4 * aa * cc >= 0) {
        
            x = ll();
            if (x <= r && x >= l) {
                double ans = f(x);
                if (ans > result) {
                    result = ans;
                }
            }
            x = rr();
            if (x <= r && x >= l) {
                double ans = f(x);
                if (ans > result) {
                    result = ans;
                }
            }
            
        }
        x = l;
        if (x <= r && x >= l) {
            double ans = f(x);
            if (ans > result) {
                result = ans;
            }
        }
        x = r;
        if (x <= r && x >= l) {
            double ans = f(x);
            if (ans > result) {
                result = ans;
            }
        }
        }
        printf("%.2lf\n", result);
    }
}
