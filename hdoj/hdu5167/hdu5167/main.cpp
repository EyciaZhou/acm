//
//  main.cpp
//  bc28b
//
//  Created by eycia on 15/1/31.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

long long fib[50];

vector<long long> has;
vector<int> has2;

map<long long, int> mem2;

void dfs(int p, long long ans) {
    //cout << ans << endl;
    mem2[ans] = p;
    
    has2.push_back(ans);
    
    if (p >= has.size()) {
        return;
    }
    
    if (ans * has[p] <= 1000000000) {
        if (mem2[ans * has[p]] < p) {
            dfs(p, ans * has[p]);
        }
    }
    
    if (mem2[ans] < p+1) {
        dfs(p+1, ans);
    }
}

int main(int argc, const char * argv[]) {
    fib[0] = 0;
    fib[1] = 1;
    has.push_back(0);
    has.push_back(1);
    has2.push_back(1);
    has2.push_back(0);
    
    for (int i = 2; i < 10000; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i] > 1000000000) {
            break;
        }
        has.push_back(fib[i]);
        has2.push_back(fib[i]);
    }
    
    sort(has.begin(), has.end());
    vector<long long>::iterator iter=unique(has.begin(), has.end());
    has.erase(iter, has.end());
    
    
    dfs(2, 1);
    
    sort(has2.begin(), has2.end());
    vector<int>::iterator iter2=unique(has2.begin(), has2.end());
    has2.erase(iter2, has2.end());
    
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n;
        scanf("%d", &n);
        if (*lower_bound(has2.begin(), has2.end(), n) == n) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}