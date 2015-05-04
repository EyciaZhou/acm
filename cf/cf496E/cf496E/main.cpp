//
//  main.cpp
//  cf496E
//
//  Created by eycia on 14/12/23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int px[100005], py[100005];

pair<int, int> part[100005];
pair<pair<int, int>, int> arc[100005];

stack<int> ans;

int n, m;
bool can;

void ttr(int p1, int p2) {
    
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &part[i].first, &part[i].second);
    }
    sort(part, part+n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &arc[i].first.first, &arc[i].first.second, &arc[i].second);
    }
    sort(arc, arc+m);
    can = false;
    ttr(0, 0);
}
