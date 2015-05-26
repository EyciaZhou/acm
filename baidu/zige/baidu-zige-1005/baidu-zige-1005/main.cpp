//
//  main.cpp
//  baidu-zige-1005
//
//  Created by eycia on 24/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int > > kq;
queue<pair<pair<int, int>, int > > nq;

int kx, ky, nx, ny, n, m, k;
bool vk[1005][1005];
bool vn[1005][1005];

int stkx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int stky[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int stnx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int stny[8] = {1, 2, 2, 1, -1, -2, -2, -1};

#define xx first.first
#define yy first.second
#define ste second
#define mp make_pair

int bfs() {
    while (!kq.empty()) kq.pop();
    while (!nq.empty()) nq.pop();
    memset(vk, false, sizeof(vk));memset(vn, false, sizeof(vn));
    kq.push(mp(mp(kx, ky), 1));nq.push(mp(mp(nx, ny), 1));
    bool isk = true;
    while (!kq.empty() && !nq.empty()) {
        if (isk) {
            int cur = kq.front().ste;
            if (cur > k) return -1;
            memset(vk, false, sizeof(vk));
            while (cur == kq.front().ste) {
                pair<pair<int, int>, int > now = kq.front();
                kq.pop();
                for (int i = 0; i < 8; i++) {
                    int nx = now.xx+stkx[i], ny = now.yy+stky[i];
                    if (1 <= nx &&  nx <= n && 1 <= ny &&  ny <= m && !vk[nx][ny]) {
                        vk[nx][ny] = true;
                        kq.push(mp(mp(nx, ny), now.ste+1));
                    }
                }
            }
        } else {
            int cur = nq.front().ste;
            if (cur > k) return -1;
            memset(vn, false, sizeof(vn));
            while (cur == nq.front().ste) {
                pair<pair<int, int>, int > now = nq.front();
                nq.pop();
                for (int i = 0; i < 8; i++) {
                    int nx = now.xx+stnx[i], ny = now.yy+stny[i];
                    if (1 <= nx &&  nx <= n && 1 <= ny &&  ny <= m && !vn[nx][ny]) {
                        if (vk[nx][ny]) return cur;
                        vn[nx][ny] = true;
                        nq.push(mp(mp(nx, ny), now.ste+1));
                    }
                }
            }
        }
        isk = !isk;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int t;
    scanf("%d", &t);
    for (int ff = 1; ff <= t; ff++) {
        printf("Case #%d:\n", ff);
        scanf("%d %d %d", &n, &m, &k);
        
        scanf("%d %d %d %d", &kx, &ky, &nx, &ny);
        int ans = bfs();
        if (ans < 0) {
            puts("OH,NO!");
        } else {
            printf("%d\n", ans);
        }
    }
}
