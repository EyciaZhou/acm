//
//  main.cpp
//  hiho1129
//
//  Created by eycia on 3/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int v[1000005];
int tar;

int find(int st, int en) {
    if (st >= en) {
        return st == tar ? v[st] : -1;
    }
    int p = st;
    for (int i = st + 1; i <= en; i++) {
        if (v[i] < v[p]) {
            swap(v[i], v[p+1]);
            swap(v[p], v[p+1]);
            p++;
        }
    }
    if (tar > p) {
        return find(p + 1, en);
    } else if (tar < p) {
        return find(st, p - 1);
    } else {
        return v[p];
    }
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d %d", &n, &tar);
    tar--;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    if (tar >= n || tar < 0) {
        cout << "-1" << endl;
    } else {
        cout << find(0, n-1) << endl;
    }
}