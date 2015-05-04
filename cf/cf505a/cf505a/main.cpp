//
//  main.cpp
//  cf505a
//
//  Created by eycia on 15/1/22.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool hw(string st) {
    for (int i = 0; i < st.length(); i++) {
        if (st[i] != st[st.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    string st, te;
    cin >> st;
    for (int i = 0; i < st.length(); i++) {
        te = st;
        te.erase(i, 1);
        if (hw(te)) {
            if (i >= st.length() / 2) {
                st.insert(st.length()-i-1, 1, st[i]);
            } else {
                st.insert(st.length()-i, 1, st[i]);
            }
            cout << st << endl;
            return 0;
        }
    }
    cout << "NA" << endl;
}
