//
//  main.cpp
//  baidu-zige-1002
//
//  Created by eycia on 24/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

char st[100005];

int main(int argc, const char * argv[]) {
    int t, k;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        getchar();
        gets(st);
        scanf("%d", &k);
        int sl = strlen(st);
        int ss = sl / k;
        cout << "Case #" << ff << ":" << endl;
        for (int i = 0; i < sl; i++) {
            if (i%k < sl % k)
                putchar(st[i%k*(ss+1)+i/k]);
            else
                putchar(st[sl%k+i%k*ss+i/k]);
        }
        cout << endl;
    }
}
