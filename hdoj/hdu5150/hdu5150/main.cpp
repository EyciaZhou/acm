//
//  main.cpp
//  bc24.1
//
//  Created by eycia on 14/12/27.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, a;
    while (cin >> n) {
        
        int tot = 0;
        while (n--) {
            cin >> a;
            bool flag = false;
            for (int i = 2; i <= sqrt(a); i++) {
                if (a % i == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                tot+=a;
            }
            
        }
        cout << tot << endl;
    }
}
