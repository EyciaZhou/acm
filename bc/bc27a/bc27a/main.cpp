//
//  main.cpp
//  bc27a
//
//  Created by eycia on 15/1/24.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > ch;

int main(int argc, const char * argv[]) {
    int ff, n;
    int a, b, c;
    cin >> ff;
    while (ff--) {
        cin >> n;
        ch.clear();
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            ch.push_back(make_pair(max(a, max(b, c)), i+1));
        }
        sort(ch.begin(), ch.end());
        for (int j = 0; j < n; j++) {
            if (ch[j].second == 1) {
                cout << n - j;
            }
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (ch[j].second == i) {
                    cout << " " << n - j;
                }
            }
        }
        cout << endl;
    }
}
