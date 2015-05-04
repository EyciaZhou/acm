//
//  main.cpp
//  bc23.1
//
//  Created by eycia on 14/12/20.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>

int a[1005];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int t1 = 0;
        int t2 = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                t1+=a[i];
            } else {
                t2+=a[i];
            }
            if (a[i] != a[n - i - 1]) {
                flag = true;
            }
        }
        if (!flag) {
            printf("No\n");
            continue;
        }
        if (t1 != t2) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
        
    }
}
