//
//  main.cpp
//  hdu5102
//
//  Created by eycia on 14/11/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <vector>
#include <queue>
using namespace std;

typedef pair<pair<int, int>, int> pa;

vector<int> G[100005];
queue<pa> q;

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n, k;
        int u, v;
        for (int i = 0; i < 100005; i++) {
            G[i].clear();
        }
        while (!q.empty()) q.pop();
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            q.push(make_pair(make_pair(v, u), 1));
            q.push(make_pair(make_pair(u, v), 1));
        }
        
        int res = 0;
        k *= 2;
        while (q.size() < k) {
            pa t = q.front();
            q.pop();
            res += t.second;
            k--;
            for (int i = 0; i < G[t.first.second].size(); i++) {
                if (G[t.first.second][i] != t.first.first) {
                    q.push(make_pair(make_pair(t.first.second, G[t.first.second][i]), t.second + 1));
                }
            }
        }
        
        for (int i = 0; i < k; i++) {
            if (!q.empty()) {
                res += q.front().second;
                q.pop();
            }
        }
        printf("%d\n", res/2);
    }
}
