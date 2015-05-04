//
//  main.cpp
//  并查集
//
//  Created by eycia on 14-9-23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>

inline int getf(int s) {
    if (fa[s] == s) {
        return s;
    }
    int t = s;
    while (fa[t] != t) {
        t = fa[t];
    }
    fa[s] = t;
    while (fa[s] != s) {
        s = fa[s];
        fa[s] = t;
    }
    return t;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
