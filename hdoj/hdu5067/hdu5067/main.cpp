//
//  main.cpp
//  test2
//
//  Created by eycia on 14/10/18.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int mm[55][55];
bool v[55][55][1050];
int near[55][55][1050];

int si[4] = {0, 0, 1, -1};
int sj[4] = {1, -1, 0, 0};

struct node {
    int x, y, stat;
    node (int x, int y, int stat): x(x), y(y), stat(stat) {};
};

int main(int argc, const char * argv[]) {
    int n, m;
    int temp;
    while (cin >> n >> m) {
        memset(v, false, sizeof(v));
        memset(near, 0, sizeof(near));
        int jew = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> temp;
                if (temp && !(i == 1 && j == 1)) {
                    mm[i][j] = jew;
                    jew++;
                } else {
                    mm[i][j] = 0;
                }
            }
        }
        jew--;
        v[1][1][0] = true;
        near[1][1][0] = 1;
        queue<node> q;
        node t(1, 1, 0);
        q.push(t);
        while (true) {
            if (near[1][1][(1 << jew) - 1]) {
                break;
            }
            if (q.empty()) {
                break;
            }
            node now = q.front();
            //cout << now.x << " " << now.y << " " << now.stat << endl;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                if (now.x + si[i] < 1) continue;
                if (now.y + sj[i] < 1) continue;
                if (now.x + si[i] > n) continue;
                if (now.y + sj[i] > m) continue;
                if (mm[now.x + si[i]][now.y + sj[i]]) {
                    if (!v[now.x + si[i]][now.y + sj[i]][now.stat | (1 << (mm[now.x + si[i]][now.y + sj[i]] - 1))]) {
                        v[now.x + si[i]][now.y + sj[i]][now.stat | (1 << (mm[now.x + si[i]][now.y + sj[i]] - 1))] = true;
                        near[now.x + si[i]][now.y + sj[i]][now.stat | (1 << (mm[now.x + si[i]][now.y + sj[i]] - 1))] = near[now.x][now.y][now.stat] + 1;
                        node temp(now.x + si[i], now.y + sj[i], now.stat | (1 << (mm[now.x + si[i]][now.y + sj[i]] - 1)));
                        q.push(temp);
                    }
                } else {
                    if (!v[now.x + si[i]][now.y + sj[i]][now.stat]) {
                        v[now.x + si[i]][now.y + sj[i]][now.stat] = true;
                        near[now.x + si[i]][now.y + sj[i]][now.stat] = near[now.x][now.y][now.stat] + 1;
                        node temp(now.x + si[i], now.y + sj[i], now.stat);
                        q.push(temp);
                    }
                }
            }
        }
        cout << near[1][1][(1 << jew) - 1] - 1 << endl;
    }
}
