//
//  main.cpp
//  cf510c
//
//  Created by eycia on 15/2/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

string inp[105];

vector<int> g[26];

string ans;

bool v[26];
int ii[26], oo[26];

void top(int n) {
    if (!v[n] && ii[n] == 0) {
        ans+=char('a'+n);
        v[n] = true;
        for (int i = 0; i < g[n].size(); i++) {
            ii[g[n][i]]--;
            top(g[n][i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    for (int i = 0; i < n-1; i++) {
        int p = 0;
        while (p < inp[i].length() && p < inp[i+1].length() && inp[i][p] == inp[i+1][p]) p++;
        if (p == inp[i+1].length() && inp[i+1].length() != inp[i].length()) {
            puts("Impossible");
            return 0;
        }
        if (p < inp[i].length() && p < inp[i+1].length()) {
            ii[inp[i+1][p]-'a']++;
            g[inp[i][p]-'a'].push_back(inp[i+1][p]-'a');
        }
    }
    for (int i = 0; i < 26; i++) {
        top(i);
    }
    for (int i = 0; i < 26; i++) {
        if (!v[i]) {
            puts("Impossible");
            return 0;
        }
    }
    puts(ans.c_str());
}
