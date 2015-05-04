//
//  main.cpp
//  向量运算
//
//  Created by eycia on 14-9-14.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>

class point {
public:
    double x, y;
    point() : x(0), y(0) {}
    point(double _x, double _y) : x(_x), y(_y) {}
};

class vector2 {
//vector p1 to p2
public: point *p1, *p2;
    vector2(const point &_p1, const point &_p2) : p1(_p1), p2(_p2) {}
    vector2(double x1, double y1, double x2, double y2) {
        p1 = new
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
