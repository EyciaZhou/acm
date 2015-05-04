//
//  main.cpp
//  hdu4296
//
//  Created by eycia on 14-9-10.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int s,w;
}p[100007];

bool cmp(node a,node b){
    return a.w + a.s > b.w + b.s;
}
int main(){
    int n,i;
    while (cin >> n){
        long long s = 0;
        for (i = 0; i < n; ++i){
            cin >> p[i].w >> p[i].s;
            s += p[i].w;
        }
        sort(p,p + n,cmp);
        long long ans = 0;
        for (i = 0; i < n; ++i){
            s -= p[i].w;
            long long tmp = s - p[i].s;
            if (tmp > 0) ans = max(ans,tmp);
        }
        cout << ans << endl;
    }
    return 0;
}