//
//  main.cpp
//  bc22.1
//
//  Created by eycia on 14/12/13.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cmath>


int main(int argc, const char * argv[]) {
    int ff, n;
    scanf("%d", &ff);
    while (ff--) {
        scanf("%d", &n);
        int re = 0;
        while (n > 0) {
            re = re * 2 + n % 2;
            n = n / 2;
        }
        printf("%d\n", re);
    }
}