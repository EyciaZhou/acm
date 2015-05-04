//
//  main.cpp
//  poj3253
//
//  Created by eycia on 14/12/6.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long > > heap;

int main(int argc, const char * argv[]) {
    int n, k;
    long long f, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        heap.push(k);
    }
    long long ans = 0;
    while (heap.size() > 1) {
        f = heap.top();
        heap.pop();
        l = heap.top();
        heap.pop();
        ans += f + l;
        heap.push(f+ l);
    }
    printf("%I64d\n", ans);
}
