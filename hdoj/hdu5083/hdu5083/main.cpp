//
//  main.cpp
//  p2
//
//  Created by eycia on 14/10/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <string>
#include <bitset>
#include <map>
using namespace std;

map<string, string> mm;

int atoi(string st) {
    int tot = 0;
    for (int i = 0; i < st.length(); i++) {
        tot = tot * 2 + st[i] - '0';
    }
    return tot;
}

int main(int argc, const char * argv[]) {
    int o;
    mm.insert(make_pair("ADD", "000001"));
    mm.insert(make_pair("SUB", "000010"));
    mm.insert(make_pair("DIV", "000011"));
    mm.insert(make_pair("MUL", "000100"));
    mm.insert(make_pair("MOVE", "000101"));
    mm.insert(make_pair("SET", "000110"));
    
    mm.insert(make_pair("000001", "ADD"));
    mm.insert(make_pair("000010", "SUB"));
    mm.insert(make_pair("000011", "DIV"));
    mm.insert(make_pair("000100", "MUL"));
    mm.insert(make_pair("000101", "MOVE"));
    mm.insert(make_pair("000110", "SET"));
    
    string st;
    while (cin >> o) {
        getchar();
        getline(cin, st);
        if (o) {
            int p1, p2;
            int v1 = 0, v2 = 0;
            for (int i = 0; i < st.length(); i++) {
                if (st[i] == ' ') {
                    p1 = i;
                    break;
                }
            }
            
            for (p2 = p1; st[p2] == ' '; p2++);
            p2++;
            
            if (string(st, 0, p1) == "SET") {
                while (p2 < st.length()) {
                    v1 = v1 * 10 + st[p2] - '0';
                    p2++;
                }
            } else {
                
                while (st[p2] != ',') {
                    v1 = v1 * 10 + st[p2] - '0';
                    p2++;
                }
                p2+=2;
                while (p2 < st.length()) {
                    v2 = v2 * 10 + st[p2] - '0';
                    p2++;
                }
                
            }
            bitset<5> r0(v1);
            bitset<5> r1(v2);
            cout << mm[string(st, 0, p1)] << r0 << r1 << endl;
        } else {
            if (mm.find(string(st, 0, 6)) ==  mm.end()) {
                cout << "Error!" << endl;
            } else {
                if (string(st, 6, 5) == "00000") {
                    cout << "Error!" << endl;
                    continue;
                }
                if (string(st, 0, 6) == "000110") {
                    if (string(st, 11, 5) != "00000") {
                        cout << "Error!" << endl;
                        continue;
                    }
                    cout << "SET R" << atoi(string(st, 6, 5)) << endl;
                } else {
                    if (string(st, 11, 5) == "00000") {
                        cout << "Error!" << endl;
                        continue;
                    }
                    cout << mm[string(st, 0, 6)] << " R" << atoi(string(st, 6, 5)) << ",R" << atoi(string(st, 11, 5)) << endl;
                }
            }
        }
    }
}
