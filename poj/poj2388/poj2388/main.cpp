//
//  main.cpp
//  poj2388
//
//  Created by eycia on 14/12/5.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <algorithm>
#include <cstdio>

struct node {
    int k, v;
    
    bool operator< (const node &other) const {
        return k < other.k;
    }
} li[10005];


int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &li[i].k);
        li[i].v = i+1;
    }
    std::sort(li, li + n);
    printf("%d\n", li[n / 2].k);
}
