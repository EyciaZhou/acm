//
//  main.cpp
//  hdu5001
//
//  Created by eycia on 14/12/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <vector>
using namespace std;

vector<int> mm[55];
int ma[55];

double dd[4][55];

int main(int argc, const char * argv[]) {
    int ff, xx, yy;
    scanf("%d", &ff);
    while (ff--) {
        int n, m, d;
        scanf("%d %d %d", &n, &m, &d);
        memset(ma, 0, sizeof(ma));
        for (int i = 0; i < 55; i++) {
            mm[i].clear();
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &xx, &yy);
            mm[xx].push_back(yy);
            mm[yy].push_back(xx);
            ma[xx]++;
            ma[yy]++;
        }
        for (int u = 1; u <= n; u++) {
            double tot = 1.0/n;
            memset(dd, 0, sizeof(dd));
            for (int i = 1; i <= n; i++) {
                dd[0][i] = 1.0/n;
            }
            for (int i = 1; i <= d; i++) {
                for (int j = 0; j <= n; j++) {
                    dd[i%2][j] = 0;
                }
                for (int j = 1; j <= n; j++) {
                    if (j == u) continue;
                    double te = dd[(i+1)%2][j] / ma[j];
                    for (int k = 0; k < mm[j].size(); k++) {
                        if (ma[j] != 0) {
                            dd[i%2][mm[j][k]] += te;
                        }
                    }
                }
                tot += dd[i%2][u];
            }
            printf("%.10f\n", 1-tot);
        }
    }
}
/*
 2
 5 4 100
 1 2
 2 3
 3 4
 4 5
*/