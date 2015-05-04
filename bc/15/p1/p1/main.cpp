//
//  main.cpp
//  p1
//
//  Created by eycia on 14/10/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>

char st1[25];
char st2[25];
char st3[50];

int main(int argc, const char * argv[]) {
    while (scanf("%s", st1) != EOF) {
        scanf("%s", st2);
        int p1 = 0, p2 = 0;
        for (int i = 0; i < strlen(st1); i++) {
            if (st1[i] == '_') {
                p1 = i + 1;
            }
        }
        for (int i = 0; i < strlen(st2); i++) {
            if (st2[i] == '_') {
                p2 = i + 1;
            }
        }
        int p = 0;
        for (int i = p1; i < strlen(st1); i++) {
            st3[p++] = st1[i];
        }
        st3[p++] = '_';
        st3[p++] = 's';
        st3[p++] = 'm';
        st3[p++] = 'a';
        st3[p++] = 'l';
        st3[p++] = 'l';
        st3[p++] = '_';
        for (int i = p2; i < strlen(st2); i++) {
            st3[p++] = st2[i];
        }
        st3[p] = '\0';
        printf("%s\n", st3);
    }
}
