//
//  main.cpp
//  zeroone
//
//  Created by eycia on 14-9-25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int one(int value)
{
    value = (value & 0x55555555) + ((value >> 1) & 0x55555555);
    value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
    value = (value & 0x0F0F0F0F) + ((value >> 4) & 0x0F0F0F0F);
    value = (value & 0x00FF00FF) + ((value >> 8) & 0x00FF00FF);
    value = (value & 0x0000FFFF) + ((value >> 16) & 0x0000FFFF);
    return value;
}

int main(int argc, const char * argv[]) {
    while (true) {
        int a;
        scanf("%d", &a);
        printf(int(log(a) / log(2) - 0.0000001) + 1 - one(a) >= one(a) ? "B\n" : "A\n");
    }
}
