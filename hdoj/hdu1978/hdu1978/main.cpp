//
//  main.cpp
//  hdu1978
//
//  Created by eycia on 14/11/2.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int mm[200][200];
int ans[200][200];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n, m;
        scanf("%d %d", &n, &m);
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &mm[i][j]);
            }
        }
        ans[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n - 1 && j == m - 1){
                    break;
                }
                int rest = mm[i][j];
                int ways = ans[i][j];
                //printf("%d\n", ways);
                for (int ii = i; ii <= i + rest; ii++) {
                    for (int jj = j; jj <= j + i + rest - ii; jj++) {
                        ans[ii][jj] = (ans[ii][jj] + ways) % 10000;
                    }
                }
            }
        }
        printf("%d\n", ans[n-1][m-1]);
    }
}
