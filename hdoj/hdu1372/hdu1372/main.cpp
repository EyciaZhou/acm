//
//  main.cpp
//  hdu1372
//
//  Created by eycia on 14/11/2.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

bool v[10][10];
int mm[10][10];

int sti[8] = {1, -1, 2, -2, 1, -1, 2, -2};
int stj[8] = {-2, -2, -1, -1, 2, 2, 1, 1};

int main(int argc, const char * argv[]) {
    char c1, c2;
    int a1, a2;
    int b1, b2;
    while (scanf("%c%d %c%d", &c1, &a1, &c2, &a2) != EOF) {
        getchar();
        queue<pair<int, int> > sta;
        b1 = c1 - 'a' + 1;
        b2 = c2 - 'a' + 1;
        memset(v, false, sizeof(v));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                mm[i][j] = -1;
            }
        }
        v[a1][b1] = true;
        mm[a1][b1] = 0;
        sta.push(make_pair(a1, b1));
        while (!sta.empty()) {
            pair<int, int> p = sta.front();
            
            int p1 = p.first;
            int p2 = p.second;
            //printf("%d %d\n", p1, p2);
            sta.pop();
            if (p1 == a2 && p2 == b2) {
                break;
            }
            for (int i = 0; i < 8; i++) {
                if (p1 + sti[i] < 1 || p1 + sti[i] > 8 || p2 + stj[i] < 1 || p2 + stj[i] > 8) {
                    continue;
                }
                if (!v[p1+sti[i]][p2+stj[i]]) {
                    v[p1+sti[i]][p2+stj[i]] = true;
                    mm[p1+sti[i]][p2+stj[i]] = mm[p1][p2] + 1;
                    //printf("from %d %d to %d %d\n", p1, p2, p1+sti[i], p2+stj[i]);
                    sta.push(make_pair(p1+sti[i], p2+stj[i]));
                }
            }
        }
        printf("To get from %c%d to %c%d takes %d knight moves.\n", c1, a1, c2, a2, mm[a2][b2]);
    }
}
