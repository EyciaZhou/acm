//
//  main.cpp
//  bc21.1
//
//  Created by eycia on 14/12/6.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>

int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d", &n) != EOF) {
        bool f = true;
        if (n - 15 > 0) {
            if (f) {
                f = false;
            } else {
                printf(" ");
            }
            printf("%d", n - 15);
        }
        if (n - 7 > 0) {
            if (f) {
                f = false;
            } else {
                printf(" ");
            }
            printf("%d", n - 7);
        }
        if (n - 4 > 0) {
            if (f) {
                f = false;
            } else {
                printf(" ");
            }
            printf("%d", n - 4);
        }
        if (n - 2 > 0) {
            if (f) {
                f = false;
            } else {
                printf(" ");
            }
            printf("%d", n - 2);
        }
        if (n - 1 > 0) {
            if (f) {
                f = false;
            } else {
                printf(" ");
            }
            printf("%d", n - 1);
        }
        printf("\n");
    }
}
