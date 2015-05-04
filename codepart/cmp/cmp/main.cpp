//
//  main.cpp
//  cmp
//
//  Created by eycia on 14-9-23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>

/*
 概率：之前不可能＊现在可能
*/
bitset<5> r0(v1);
bitset<5> r1(v2);
cout << mm[string(st, 0, p1)] << r0 << r1 << endl;

typedef struct node{
    int deadline;
    int score;
    
    bool operator<(const node& a) const
    {
        if (score == a.score) {
            return deadline < a.deadline;
        }
        return score < a.score;
    }
} *pnode;

bool cmp(const node &a, const node &b) {
    return b.deadline < a.deadline;
}

struct cmp2 {
    bool operator()(const pnode &na, const pnode &nb)
    {
        if (na->score == nb->score) {
            return na->deadline < nb->deadline;
        }
        return na->score < nb->score;
    }
};

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
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
