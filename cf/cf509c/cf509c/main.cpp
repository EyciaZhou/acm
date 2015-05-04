//
//  main.cpp
//  cf509c
//
//  Created by eycia on 15/1/31.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

string f[365][365];
string g[365][365];
bool v[365][365];

inline bool les(string &a, string &b) {
    if (a.length() > b.length()) {
        return false;
    }
    return a < b;
}

int main(int argc, const char * argv[]) {
    memset(v, false, sizeof(v));
    memset(v[0], true, sizeof(v[0]));
    for (int i = 1; i <= 355; i++) {
        for (int j = 0; j <= 355; j++) {
            for (int k = 0; k <= 9; k++) {
                if (v[i-1][j] && !v[i][j+k]) {
                    f[i][j+k] = f[i-1][j];
                    f[i][j+k] += char('0' + k);
                    v[i][j+k] = true;
                }
            }
        }
        for (int j = 1; j <= 355; j++) {
            if (f[i][j][0] == '0') {
                g[i][j] = "1";
                g[i][j] += f[i-1][j-1];
            } else {
                g[i][j] = f[i][j];
            }
        }
    }
    
    int n, k, lstk = 0;
    cin >> n;
    int c = 1;
    string lst = "0";
    string now;
    
    while (n--) {
        cin >> k;
        
        int p = lst.length()-1;
        int qz = lstk - lst[p] + '0';

        if (int(ceil(k / 9.0)) <= c && lst.length() > 1)
        do {
            p -= 1;
            qz -= lst[p] - '0';
            
            if (qz < 0 || p < 0) {
                break;
            }
            
            //if (p-1 > 0)
            for (int i = lst[p] - '0'; i <= 9; i++) {
                if (k - qz - i < 0) {
                    break;
                }
                
                if (ceil((k-qz-i) / 9.0) > c-p-1) {
                    continue;
                }
                
                now = string(lst, 0, p);
                now += char(i + '0');
                now += f[c-p-1][k-qz-i];

                if (!(les(now, lst) || now == lst)) {
                    break;
                }
            }
            
        } while (les(now, lst) || now == lst);
        
        c = max(c, int(ceil(k / 9.0)));
        
        if (les(now, lst) || now == lst) {
            now = g[c][k];
        }
        
        while (les(now, lst) || now == lst) {
            c++;
            now = g[c][k];
        }
        
        cout << now << endl;
        lst = now;
        lstk = k;
    }
}
