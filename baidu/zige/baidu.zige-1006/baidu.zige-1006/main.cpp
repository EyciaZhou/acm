//
//  main.cpp
//  baidu.zige-1006
//
//  Created by eycia on 24/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

inline double gs1(int n) {
    return 1 + (n - 2) * 19.0/27;
}

inline double gs2(int n) {
    return  (46 - 38.0/n) / (19 - 11.0/n);
}

int main(int argc, const char * argv[]) {
    int t, n;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        scanf("%d", &n);
        printf("Case #%d:\n", ff);
        printf("%.6lf %.6lf\n", gs1(n), gs2(n));
    }
}
