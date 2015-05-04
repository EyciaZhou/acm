//
//  main.cpp
//  poj1035
//
//  Created by eycia on 14/12/5.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

vector<string> dic;
map<string, int> mm;

int main(int argc, const char * argv[]) {
    char te[20];
    int rank = 0;
    while (true) {
        scanf("%s", te);
        if (strlen(te) == 1 && te[0] == '#') {
            break;
        }
        mm[string(te)] = rank++;
        dic.push_back(string(te));
    }
    while (true) {
        char tt;
        vector<int > ans;
        scanf("%s", te);
        if (strlen(te) == 1 && te[0] == '#') {
            break;
        }
        int lte = strlen(te);
        te[strlen(te) + 1] = '\0';
        string st = string(te);
        if (mm.find(st) != mm.end()) {
            printf("%s is correct\n", st.c_str());
        } else {
            string ss = string(te);
            for (int i = 0; i < st.length(); i++) {
                tt = st[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    st[i] = c;
                    map<string, int>::iterator it = mm.find(st);
                    if (it != mm.end()) {
                        ans.push_back(it->second);
                    }
                }
                st[i] = tt;
            }
            for (int i = 0; i < st.length(); i++) {
                string pa = string(te, te+i) + string(te+i+1, te+lte);
                map<string, int>::iterator it = mm.find(pa);
                if (it != mm.end()) {
                    ans.push_back(it->second);
                }
            }
            for (int i = 0; i <= st.length(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string pa =  string(te, te+i) + c + string(te+i, te+lte);
                    map<string, int>::iterator it = mm.find(pa);
                    if (it != mm.end()) {
                        ans.push_back(it->second);
                    }
                }
            }
            sort(ans.begin(), ans.end());
            int j = 1;
            for (int i = 1; i < ans.size(); i++) {
                if (ans[i] != ans[i-1]) {
                    ans[j++] = ans[i];
                }
            }
            printf("%s:", te);
            if (ans.size() != 0) {
                for (int i = 0; i < j; i++) {
                    printf(" %s", dic[ans[i]].c_str());
                }
            }
            printf("\n");
        }
    }
}
