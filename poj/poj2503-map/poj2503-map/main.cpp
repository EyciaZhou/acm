//
//  main.cpp
//  poj2503-map
//
//  Created by eycia on 14-9-20.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

map<string, string> mm;

int main(int argc, const char * argv[]) {
    char cc[25];
    while (true) {
        gets(cc);
        if (strlen(cc) == 0) {
            break;
        }
        for (int i = 0; i < strlen(cc); i++) {
            if (cc[i] == ' ') {
                mm[string(cc + i + 1, strlen(cc) - i - 1)] = string(cc, i);
                break;
            }
        }
    }
    while (gets(cc) != NULL) {
        if (strlen(cc) == 0) {
            break;
        }
        if (mm.find(string(cc, strlen(cc))) != mm.end()) {
            cout << mm[string(cc, strlen(cc))] << endl;
        } else {
            cout << "eh\n";
        }
    }
}
