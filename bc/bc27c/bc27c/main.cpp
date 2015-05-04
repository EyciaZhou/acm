//
//  main.cpp
//  bc27c
//
//  Created by eycia on 15/1/24.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct tnode {
    map<double, int> n;
    int ti;
    
    //ac auto
    int v;
    int fa;
    int f;
    int de;
};

tnode trie[1000005];

void dof() {
    queue<int > qu;
    for (int i = 0; i < 4; i++) {
        for (map<double, int>::iterator it = trie[0].n.begin(); it != trie[0].n.end(); it++) {
            qu.push(it->second);
        }
    }
    
    while (!qu.empty()) {
        int p = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++) {
            if (trie[p].n[i] != -1) {
                qu.push(trie[p].n[i]);
            }
        }
        int k = trie[p].fa;
        k = trie[k].f;
        while (trie[ k ].n[ trie[p].v ] != -1) {
            k = trie[k].f;
            if (k == -1) {
                break;
            }
        }
        if (k == -1) {
            trie[p].f = 0;
        } else {
            trie[p].f = trie[ k ].n[ trie[p].v ];
        }
    }
}

int next(int n, int ne, int k) {
    int k2 = n;
    while (trie[k2].n[ne] == -1) {
        k2 = trie[k2].f;
        if (k2 == -1) {
            break;
        }
    }
    if (k2 == -1) {
        return 0;
    } else {
        k2 = trie[k2].n[ne];
        int k3 = k2;
        while (k2 != -1) {
            trie[k2].ti |= k;
            k2 = trie[k2].f;
        }
        return k3;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
