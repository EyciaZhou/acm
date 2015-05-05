//
//  main.cpp
//  hiho1053
//
//  Created by eycia on 5/5/15.
//  Copyright (c) 2015 eycia. All rights reserved.
//

#include <cstdio>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int r, n;

int vs1[100005];
int vs2[100005];
pair<int, int> vs[100005];

list<int> l1;
list<int> l2;

bool check(int ma) {
    l1.clear();
    l2.clear();
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (p < n)
            while (p < n && vs1[p]-r <= vs1[i]) {
                l1.push_back(vs1[p]);
                l2.push_back(vs2[p]);
                p++;
            }
        while (!l1.empty() && (l1.front()+r < vs1[i] || l2.front() == 0)) {
            if (l2.front() != 0) {
                return false;
            }
            l1.pop_front();
            l2.pop_front();
        }
        int lim = ma;
        for (list<int>::iterator j = l1.begin(), k = l2.begin(); j != l1.end(); j++, k++) {
            if (lim <= 0) break;
            if (*k > lim) {
                *k -= lim;
                lim = 0;
            } else {
                lim -= *k;
                *k = 0;
            }
        }
    }
    while (!l1.empty() && l2.front() == 0) {
        l1.pop_front();
        l2.pop_front();
    }
    if (l1.size() > 0) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int t;
    //freopen("/Volumes/bin/code_old/acm/hiho/hiho1053/hiho1053/in", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &r);
        int mx = 0;
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &vs[i].first, &vs[i].second);
            if (vs[i].second > mx) {
                mx = vs[i].second;
            }
            tot = tot + (long long)vs[i].second;
        }
        sort(vs, vs+n);
        for (int i = 0; i < n; i++) {
            vs1[i] = vs[i].first;
            vs2[i] = vs[i].second;
        }
        int l = max(tot/n-1, (long long)0), r = mx;
        while(l!=r){
            int mid=(l+r)/2;
            if(check(mid)) {r=mid;}
            else l=mid+1;
        }
        printf("%d\n", l);
    }
}
