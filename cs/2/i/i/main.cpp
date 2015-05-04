//
//  main.cpp
//  i
//
//  Created by eycia on 14-8-30.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    char st[55];
    cin >> T;
    while (T--) {
        int n, tot = 0;
        cin >> n;
        while (getchar() != '\n') ;
        while (n--) {
            gets(st);
            bool flag = false;
            if (strlen(st) > 18 || strlen(st) < 6) {
                flag = true;
            }
            if (!((st[0] <= 'Z' && st[0] >= 'A') || (st[0] <= 'z' && st[0] >= 'a'))) {
                flag = true;
            }
            for (int i = 0; i < strlen(st); i++) {
                if (!((st[i] <= 'Z' && st[i] >= 'A') || (st[i] <= 'z' && st[i] >= 'a') || (st[i] <= '9' && st[i] >= '0') || st[i] == '_')) {
                    flag = true;
                }
            }
            if (!flag) {
                tot++;
            }
        }
        cout << tot << endl;
    }
}
