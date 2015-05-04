//
//  main.cpp
//  hdu5198
//
//  Created by eycia on 28/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    while (cin >> s) {
        if (s.length() % 3 != 0) {
            cout << "NO" << endl;
            continue;
        }
        int sl = s.length();
        if (s[0] == s[sl/3] || s[0] == s[sl/3*2] || s[sl/3] == s[sl/3*2]) {
            cout << "NO" << endl;
            continue;
        }
        bool N = false;
        int k = 0;
        for (int i = 1; i < sl / 3; i++) {
            if (s[i+k] != s[i+k-1]) {
                N = true;
                break;
            }
        }
        
        k = sl/3;
        for (int i = 1; i < sl / 3; i++) {
            if (s[i+k] != s[i+k-1]) {
                N = true;
                break;
            }
        }
        
        k = sl/3*2;
        for (int i = 1; i < sl / 3; i++) {
            if (s[i+k] != s[i+k-1]) {
                N = true;
                break;
            }
        }
        
        if (N) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}