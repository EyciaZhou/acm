//
//  main.cpp
//  hdu5113
//
//  Created by eycia on 14/12/1.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
    int nu;
    int cn;
    
    inline bool operator<(const node& a) const
    {
        return nu > a.nu;
    }
} ks[30];

//int ks[30];
int ma[10][10];
int n, m, kk;
bool cc[30][10][10];

bool dfs(int c, int k, int ii, int jj) {
    //printf("%d %d %d %d\n", c, k, ii, jj);
    if (c > kk) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < m; j++) {
                printf("%d ", ks[ma[i][j]].cn);
            }
            printf("%d\n", ks[ma[i][m]].cn);
        }
        return true;
    }
    
    if (k == ks[c].nu) {
        return dfs(c+1, 0, 1, 1);
    }
    for (int j = jj; j <= m; j++) {
        if (!ma[ii][j]) {
            if (cc[c][ii-1][j]&&
                cc[c][ii+1][j]&&
                cc[c][ii][j+1]&&
                cc[c][ii][j-1]) {
                cc[c][ii][j] = false;
                ma[ii][j] = c;
                if (dfs(c, k+1, ii, j+2)) {
                    return true;
                }
                cc[c][ii][j] = true;
                ma[ii][j] = 0;
            }
        }

    }
    
    for (int i = ii+1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!ma[i][j]) {
                if (cc[c][i-1][j]&&
                    cc[c][i+1][j]&&
                    cc[c][i][j+1]&&
                    cc[c][i][j-1]) {
                    cc[c][i][j] = false;
                    ma[i][j] = c;
                    if (dfs(c, k+1, i, j+2)) {
                        return true;
                    }
                    cc[c][i][j] = true;
                    ma[i][j] = 0;
                }
            }
        }
    }
    return false;
}
/*
 
2
 5 5 10
 1 2 3 4 5 6 1 1 1 1
 5 5 2
 16 9
 */

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        memset(ma, 0, sizeof(ma));
        memset(cc, true, sizeof(cc));
        scanf("%d %d %d", &n, &m, &kk);
        for (int i = 1; i <= kk; i++) {
            scanf("%d", &ks[i].nu);
            ks[i].cn = i;
        }
        sort(ks+1, ks+kk+1);/*
        node te;
        for (int i = 1; i <= kk / 2; i++) {
            te = ks[i];
            ks[i] = ks[kk - i + 1];
            ks[kk - i + 1] = te;
        }*/
        printf("Case #%d:\n", tt);
        if (!dfs(1, 0, 1, 1)) {
            printf("NO\n");
        }
    }
}
