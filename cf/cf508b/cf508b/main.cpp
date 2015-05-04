//
//  main.cpp
//  cf508b
//
//  Created by eycia on 15/1/28.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char ss[100005];

int main(int argc, const char * argv[]) {
    scanf("%s", ss);
    int ll = -1;
    int sl = strlen(ss) - 1;
    char lst = ss[sl], tmp;
    
    for (int i = 0; i < sl; i++) {
        if ((ss[i] - '0') % 2 == 0) {
            if ((lst - '0') > ss[i] - '0') {
                tmp = ss[i];
                ss[i] = ss[sl];
                ss[sl] = tmp;
                break;
            } else {
                ll = i;
            }
        }
    }
    
    if ((ss[sl] - '0') % 2 == 0) {
        printf("%s\n", ss);
    } else {
        if (ll < 0) {
            puts("-1");
        } else {
            tmp = ss[ll];
            ss[ll] = ss[sl];
            ss[sl] = tmp;
            printf("%s\n", ss);
        }
    }
}
