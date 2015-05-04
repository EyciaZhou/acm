//
//  main.cpp
//  hdu5106
//
//  Created by eycia on 14/11/16.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <stdio.h>
#include <string.h>

const int N=2002;
int str[N][N];//初始化为-1
int C(int m,int n) {
    
    if(str[m][n]!=-1)return str[m][n];
    if(m==n || n==0)return str[m][n]=1;
    if(m<n)return str[m][n]=0;
    return str[m][n]=C(m-1,n-1)+C(m-1,n);
}

int main() {
    int n;
    char R[2005], tm;
    memset(str, -1, sizeof(str));
    int bin[2005], bp;
    while (scanf("%d", &n) != EOF) {
        scanf("%s", R);
        bp = 0;
        int le = strlen(R);
        for (int i = 0; i < le / 2; i++) {
            tm = R[i] - '0';
            R[i] = R[le - i - 1] - '0';
            R[le - i - 1] = tm;
        }
        memset(bin, 0, sizeof(bin));
        for (int i = 0; i < le; i++) {
            bin[i] = R[i];
        }
        
        int tot = 0;
        for (int i = 2002; i >= 0; i--) {
            if (bin[i]) {
                printf("%d %d %d\n", i, n, C(i, n));
                if (n < 0) {
                    continue;
                }
                tot = (tot + C(i, n)) % 1000000007;
                n--;
            }
        }
        printf("%d\n", tot);
    }
}