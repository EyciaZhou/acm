//
//  main.cpp
//  cf490C
//
//  Created by eycia on 15/1/8.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

char ss[1000005];
bool zz[1000005];
bool z2[1000005];


int main(int argc, const char * argv[]) {
    int a, b;
    unsigned long sl;
    memset(zz, false, sizeof(zz));
    cin >> ss;
    cin >> a >> b;
    sl = strlen(ss);
    int y = 0;
    for (int i = 0; i < sl-1; i++) {
        y = y * 10 + ss[i] - '0';
        y = y % a;
        if (!y) {
            zz[i] = true;
        }
    }
    
    y = 0;
    int y2 = 1;
    for (int i = sl-1; i > 0; i--) {
        y = y + y2 * (ss[i] - '0');
        y = y % b;
        y2 = y2 * 10 % b;
        if (!y) {
            z2[i-1] = true;
        }
    }
    
    for (int k = 0; k < sl-1; k++) {
        if (zz[k] && z2[k] && ss[k + 1] != '0') {
            
                cout << "YES\n";
                char te = ss[k+1];
                ss[k+1] = '\0';
                cout << ss << endl;
                ss[k+1] = te;
                cout << ss+k+1;
                return 0;
        }
    }
    cout << "NO\n";
}
