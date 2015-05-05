//
//  main.cpp
//  hiho1039
//
//  Created by eycia on 5/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string r[] = {"A", "B", "C"};
string tmp;

int func(string tm) {
    tm = "-" + tm + "-";
    string t2;
    for (int i = 1; i < tm.size()-1; i++) {
        if (tm[i] != tm[i-1] && tm[i] != tm[i+1]) {
            t2.push_back(tm[i]);
        }
    }
    int mu = tmp.size() - t2.size();
    tmp = t2;
    return mu;
}

int main(int argc, const char * argv[]) {
    int t;
    string st;
    cin >> t;
    while (t--) {
        cin >> st;
        int sl = st.size();
        int mx = 0;
        for (int i = 0; i <= sl; i++) {
            for (char ch = 0; ch < 3; ch++) {
                tmp = st;
                tmp.insert(i, r[ch]);
                int tot = 0;
                while (true) {
                    int tm = func(tmp);
                    tot += tm;
                    if (tm == 0) {
                        break;
                    }
                }
                if (tot > mx) {
                    mx = tot;
                }
            }
        }
        cout << mx << endl;
    }
}
