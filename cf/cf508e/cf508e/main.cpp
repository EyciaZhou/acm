//
//  main.cpp
//  cf508e
//
//  Created by eycia on 15/4/28.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int ll[605];
int rr[605];

string ans[605][605];
bool v[605][605];
bool succ[605][605];

bool ff(int l, int r) {
    if (r < l) {
        return true;
    }
    
    if (v[l][r]) {
        return succ[l][r];
    }
    
    if (l == r) {
        if (ll[l] != 1) {
            v[l][r] = true;
            succ[l][r] = false;
            ans[l][r] = "";
            return false;
        } else {
            v[l][r] = true;
            succ[l][r] = true;
            ans[l][r] = "()";
            return true;
        }
    }
    int sl = (r - l + 1) * 2;
    for (int i = l; i <= r; i++) {
        if ((i-l)*2+1 > rr[l]) continue;
        if ((i-l)*2+1 < ll[l]) continue;
        if (v[l+1][i] && !succ[l+1][i]) continue;
        if (v[i+1][r] && !succ[i+1][r]) continue;
        
        bool a1 = ff(l+1, i);
        if (!a1) continue;
        bool a2 = ff(i+1, r);
        if (a1 && a2) {
            v[l][r] = true;
            succ[l][r] = true;
            ans[l][r] = "(" + ans[l+1][i] + ")" + ans[i+1][r];
            return true;
        }
    }
    v[l][r] = true;
    succ[l][r] = false;
    return false;
}

int main(int argc, const char* argv[]) {
    int n;
    memset(v, false, sizeof(v));
    memset(succ, false, sizeof(succ));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ll[i] >> rr[i];
    }
    
    if (ff(1, n)) {
        cout << ans[1][n] << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
