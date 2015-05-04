//
//  main.cpp
//  bc16.2
//
//  Created by eycia on 14/11/1.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

int a[1005];
int l[1005];
bool t[1005];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        memset(l, 0, sizeof (l));
        memset(t, false, sizeof(t));
        a[0] = -999999999;
        l[0] = 0;
        for (int i = 1; i <= n; i++) {
            int largest = -1;
            int times = 0;
            for (int j = 0; j < i; j++) {
                if (l[j] == largest) {
                    times++;
                }
                if (l[j] > largest && a[i] > a[j]) {
                    largest = l[j];
                    if (t[j]) {
                        times = 2;
                    } else {
                        times = 1;
                    }
                }
            }
            if (times > 1) {
                t[i] = true;
            }
            l[i] = largest + 1;
        }
        int largest = -1;
        int times = 0;
        for (int i = 1; i <= n; i++) {
            if (l[i] == largest) {
                times++;
            }
            if (l[i] > largest) {
                largest = l[i];
                if (t[i]) {
                    times = 2;
                } else {
                    times = 1;
                }
            }
        }
        if (times > 1) {
            printf("%d\n", largest);
        } else {
            printf("%d\n", largest - 1);
        }
    }
}
