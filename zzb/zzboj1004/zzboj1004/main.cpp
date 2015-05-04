//
//  main.cpp
//  zzboj1004
//
//  Created by eycia on 21/4/15.
//  Copyright (c) 2015 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<pair<int, double> > g[555];
double dis[555];
bool v[555];

void spfa() {
    for (int i = 0; i < 555; i++) {
        dis[i] = -1;
    }
    memset(v, false, sizeof(v));
    dis[0] = 0;
    queue<int> q;
    v[0] = true;
    q.push(0);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        
        v[k] = false;
        for (int i = 0; i < g[k].size(); i++) {
            if ((dis[k] + g[k][i].second < dis[g[k][i].first] || dis[g[k][i].first] < 0)) {
                dis[g[k][i].first] = dis[k] + g[k][i].second;
                q.push(g[k][i].first);
                if (!v[g[k][i].first]) {
                    v[g[k][i].first] = true;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    double tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &tmp);
            if (tmp == 0) continue;
            
            for (int k = 0; k <= m; k++) {
                double t2 = tmp;
                for (int l = k; l <= m; l++) {
                    g[i+50*k].push_back({j+50*l, t2});
                    t2 /= 2;
                }
            }
        }
    }
    
    spfa();
    printf("%.2lf\n", dis[50*m+n-1]);
}