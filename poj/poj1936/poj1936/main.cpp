//
//  main.cpp
//  poj1936
//
//  Created by eycia on 14/12/5.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>

char pa[100005];
char pb[100005];

int main(int argc, const char * argv[]) {
    while (scanf("%s %s", pa, pb) != EOF) {
        int lpa = strlen(pa);
        int lpb = strlen(pb);
        pb[lpb] = '*';
        pb[lpb] = '\0';
        lpb++;
        int j = 0;
        for (int i = 0; i < lpa; i++) {
            while (j < lpb && pa[i] != pb[j]) {
                j++;
            }
            j++;
        }
        if (j >= lpb) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
}