//
//  main.cpp
//  poj2503-sort
//
//  Created by eycia on 14-9-20.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<string, string> ps;
vector<ps> vv;
typedef vector<ps >::iterator vi;
int tot;

struct Comparator {
    inline bool operator()(const ps& s1, const ps& s2) const {
        return s1.first < s2.first;
    }
    inline bool operator()(const ps& s1, const string& s2) const {
        return s1.first < s2;
    }
    inline bool operator()(const string& s1, const ps& s2) const {
        return s1 < s2.first;
    }
};

int main(int argc, const char * argv[]) {
    char cc[25];
    while (true) {
        gets(cc);
        if (strlen(cc) == 0) {
            break;
        }
        for (int i = 0; i < strlen(cc); i++) {
            if (cc[i] == ' ') {
                vv.push_back(pair<string, string>(string(cc + i + 1, strlen(cc) - i - 1), string(cc, i)));
                break;
            }
        }
    }
    sort(vv.begin(), vv.end(), Comparator());
    while (gets(cc) != NULL) {
        if (strlen(cc) == 0) {
            break;
        }
        string temp = string(cc, strlen(cc));
        vi i = lower_bound(vv.begin(), vv.end(), temp, Comparator());
        if (i->first == temp) {
            cout << i->second << endl;
        } else {
            cout << "eh\n";
        }
    }

}
