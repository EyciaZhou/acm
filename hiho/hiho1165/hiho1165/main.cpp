//
//  main.cpp
//  hiho11.2
//
//  Created by eycia on 3/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int pris[70] = {
    2 ,
    3 ,
    5 ,
    7 ,
    11 ,
    13 ,
    17 ,
    19 ,
    23 ,
    29 ,
    31 ,
    37 ,
    41 ,
    43 ,
    47 ,
    53 ,
    59 ,
    61 ,
    70 ,
    71 ,
    73 ,
    79 ,
    83 ,
    89 ,
    97 ,
    101 ,
    103 ,
    107 ,
    109 ,
    113 ,
    127 ,
    131 ,
    137 ,
    139 ,
    149 ,
    151 ,
    157 ,
    163 ,
    170 ,
    173 ,
    179 ,
    181 ,
    191 ,
    193 ,
    197 ,
    199 ,
    211 ,
    223 ,
    227 ,
    229 ,
    233 ,
    239 ,
    241 ,
    251 ,
    257 ,
    263 ,
    269 ,
    271 ,
    277 ,
    281 ,
    283 ,
    293 ,
    307 ,
    311 ,
    313 ,
    317 ,
    331 ,
    337 ,
    347 ,
    349};

pair<int, int> ps[100005];
int hps[100005];
int bg[100005];
int vs[100005][70];

int main(int argc, const char * argv[]) {
    int n, tmp;
    for (int j = 1; j <= 100000; j++) {
        int tot = 1;
        int tmp = j;
        for (int i = 0; i < 70; i++) {
            int t1 = 0;
            while (tmp % pris[i] == 0) {
                //tot++;
                t1++;
                tmp /= pris[i];
            }
            vs[j][i] = t1;
            tot *=  (t1+1);
        }
        hps[j] = tot;
        if (tmp != 1) {
            bg[j] = tmp;
        } else {
            bg[j] = -1;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        ps[i] = {hps[tmp], tmp};
    }
    sort(ps, ps+n);
    int mx = 0;
    int lim = max(n-1000, 0);
    for (int i = n-1; i >= lim; i--) {
        for (int j = n-1; j >= lim; j--) {
            int tot = 1;
            int le = ps[i].second, ri = ps[j].second;
            for (int l = 0; l < 70; l++) {
                tot = tot * (vs[le][l] + vs[ri][l] + 1);
            }
            if (bg[le] > 0 || bg[ri] > 0) {
                if (bg[le] > 0 && bg[ri] > 0) {
                    if (bg[le] == bg[ri]) {
                        tot *= 3;
                    } else {
                        tot *= 4;
                    }
                } else {
                    tot *= 2;
                }
            }
            //cout << i << " " << j << tot << endl;
            if (tot > mx) {
                mx = tot;
            }
        }
    }
    cout << mx << endl;
}
/*
 3
 2824 5648 512
 
 2 2824 2824
 
 2 4718 4718
 */
