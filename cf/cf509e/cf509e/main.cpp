//
//  main.cpp
//  cf509e
//
//  Created by eycia on 15/2/6.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string s;
int l;

char wtbl[6] = {'A', 'E', 'I', 'O', 'U', 'Y'};

inline bool iis(char c) {
    for (int i = 0; i < 6; i++) {
        if (c == wtbl[i]) {
            return true;
        }
    }
    return false;
}

inline int v(int k) {
    int tot = 0;
    if (iis(s[k-1])) tot++;
    if (iis(s[l-k])) tot++;
    return tot;
}

int main(int argc, const char * argv[]) {
    cin >> s;
    l = s.length();
    double a = 0, b = 0, ans = 0;
    for (int i = 1; i <= l; i++) {
        b += 1.0 / i;
    }
    for (int i = 1; i <= l / 2; i++) {
        a += 1 + i / (l+1.0-i);
        b -= 1.0 / i + 1.0 / (l+1.0-i);
        ans += (a + b * i) * v(i);
    }
    if (l % 2 == 1) {
        int i = l / 2 + 1;
        a += 1 + i / (l+1.0-i);
        b -= 1.0 / i + 1.0 / (l+1.0-i);
        ans += (a + b * i) * v(i) / 2;
    }
    cout << fixed << setprecision(10) << ans << endl;
}
