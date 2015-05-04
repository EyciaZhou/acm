//
//  main.cpp
//  b
//
//  Created by Serx on 14/12/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

map<string, string> dict;

int main(int argc, const char * argv[]) {
    int n, m;
    string s1, s2;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s1 >> s2;
        if (s1.length() <= s2.length()) {
            dict[s1] = s1;
        } else {
            dict[s1] = s2;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> s1;
        cout << dict[s1] << " ";
    }
    cout << endl;
}