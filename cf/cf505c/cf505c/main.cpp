//
//  main.cpp
//  cf505c
//
//  Created by eycia on 15/1/22.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int f[30005][505];
int floor[30005];

int main(int argc, const char * argv[]) {
    int n, d, v;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> v;
        floor[v]++;
    }
    
    memset(f, -1, sizeof(f));
    
    int mx = floor[d];
    f[d][250] = floor[d];
    
    for (int i = d; i <= 30000; i++) {
        for (int j = 0; j <= 500; j++) {
            int dis = i + j - 250 + d;
            if (dis < 0) continue;
            if (f[i][j] < 0) continue;
            
            if (dis + 1 <= 30000 && dis + 1 >= 0) {
                if (f[i][j] + floor[dis+1] > f[dis+1][j+1]) {
                    f[dis+1][j+1] = f[i][j] + floor[dis+1];
                    if (f[i][j] + floor[dis+1] > mx) {
                        mx = f[i][j] + floor[dis+1];
                    }
                }
            }
            
            if (dis <= 30000 && dis >= 0) {
                if (f[i][j] + floor[dis] > f[dis][j]) {
                    f[dis][j] = f[i][j] + floor[dis];
                    if (f[i][j] + floor[dis] > mx) {
                        mx = f[i][j] + floor[dis];
                    }
                }
            }
            
            if (j - 250 + d > 1)
            if (dis - 1 <= 30000 && dis - 1 >= 0) {
                if (f[i][j] + floor[dis-1] > f[dis-1][j-1]) {
                    f[dis-1][j-1] = f[i][j] + floor[dis-1];
                    if (f[i][j] + floor[dis-1] > mx) {
                        mx = f[i][j] + floor[dis-1];
                    }
                }
            }
        }
    }
    
    cout << mx << endl;
}
