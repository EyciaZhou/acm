//
//  main.cpp
//  hdu4999
//
//  Created by eycia on 14-9-22.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

struct too {
    char op;
    unsigned long num;
} oo[45];

int main(int argc, const char * argv[]) {
    int ff, n;
    char temp;
    cin >> ff;
    while (ff--) {
        cin >> n;
        for (int i = n-1; i >= 0; i--) {
            cin >> oo[i].op >> temp >> hex >> oo[i].num;
            cout << oo[i].op << " " << oo[i].num << endl;
        }
        for (unsigned long i = 4294967295; i > 0; i--) {
            for (int i = 0; i < n; i++) {
                switch (oo[i].op) {
                    case '+':
                    
                        break;
                    case '-':
                    
                        break;
                    case '&':
                    
                        break;
                    case '^':
                    
                        break;
                    case '|':
                    
                        break;
                }
            }
        }
    }
}
