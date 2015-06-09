//
//  main.cpp
//  bdzxfs.2
//
//  Created by eycia on 6/6/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> ps[5005][4];

#define ll long long
ll f[5005][4][4][4][4];
bool vv[5005][4][4][4][4];
#define mp make_pair

inline ll abs(ll k) {
    if (k < 0) return -k;
    return k;
}

inline ll mov(int now, int p1, int p2) {
    return abs(ps[now][p1].first - ps[now-1][p2].first) + abs(ps[now][p1].second - ps[now-1][p2].second);
}

ll ans = -1;
int n;

ll dfs(int i, int f1, int f2, int f3, int f4) {
    if (i <= 0) {
        return 0;
    }
    if (vv[i][f1][f2][f3][f4]) {
        return f[i][f1][f2][f3][f4];
    }
    bool v[4] = {false, false, false, false};
    ll mi = -1;
    
    for (int p1 = 0; p1 < 4; p1++) {
        v[p1] = true;
        for (int p2 = 0; p2 < 4; p2++) {
            if (v[p2]) continue;
            if (ps[i-1][p1].first > ps[i-1][p2].first) continue;
            v[p2] = true;
            for (int p3 = 0; p3 < 4; p3++) {
                if (v[p3]) continue;
                if (ps[i-1][p2].first > ps[i-1][p3].first) continue;
                v[p3] = true;
                for (int p4 = 0; p4 < 4; p4++) {
                    if (v[p4]) continue;
                    if (ps[i-1][p3].first > ps[i-1][p4].first) continue;
                    v[p4] = true;
                    ll c1 = dfs(i-1, p1, p2, p3, p4);
                    if (c1 < 0) continue;
                    
                    ll cost = mov(i, f1, p1) + mov(i, f2, p2) + mov(i, f3, p3) + mov(i, f4, p4) + c1;
                    //if (i==1) {
                    //    printf("%d %d %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, f1, f2, f3, f4, c1, cost);
                    //}
                    
                    if (cost < mi || mi < 0) {
                        mi = cost;
                    }
                    
                    v[p4] = false;
                }
                v[p3] = false;
            }
            v[p2] = false;
        }
        v[p1] = false;
    }
    f[i][f1][f2][f3][f4] = mi;
    vv[i][f1][f2][f3][f4] = true;
    if (i == n) {
        if (mi < ans || ans < 0) {
            ans = mi;
        }
    }
    return mi;
}

int main(int argc, const char * argv[]) {
    int t, xx, pp;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        memset(f, 0, sizeof(f));
        memset(ps, 0, sizeof(ps));
        memset(vv, false, sizeof(vv));
        scanf("%d", &n);
        ps[0][0]=mp(4, 0);
        ps[0][1]=mp(3, 0);
        ps[0][2]=mp(2, 0);
        ps[0][3]=mp(1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d %d", &xx, &pp);
                ps[i][j] = mp(pp, xx);
            }
            //sort(ps[i], ps[i]+4);
        }
        printf("Case #%d:\n", ff);
        ans = -1;
        dfs(n+1, 0, 1, 2, 3);
        cout << ans << endl;
    }
}
