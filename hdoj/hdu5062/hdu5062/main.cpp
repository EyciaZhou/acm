//
//  main.cpp
//  hdu5062
//
//  Created by eycia on 14-10-17.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
bool iis(int n) {
    int temp = n;
    vector<int> k;
    k.clear();
    while (n > 0) {
        k.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < k.size(); i++) {
        if (k[i] != k[k.size() - i - 1]) {
            return false;
        }
    }
    for (int i = 1; i < (k.size() + 1) / 2; i++) {
        if (k[i - 1] >= k[i]) {
            return false;
        }
    }
    //cout << temp << endl;
    return true;
}

int main(int argc, const char * argv[]) {
    int tot;
    
    tot = 0;
    for (int i = 1; i < 10; i++) {
        if (iis(i)) {
            tot++;
        }
    }
    cout << tot << endl;
    
    tot = 0;
    for (int i = 1; i < 100; i++) {
        if (iis(i)) {
            tot++;
        }
    }
    cout << tot << endl;
    
    tot = 0;
    for (int i = 1; i < 1000; i++) {
        if (iis(i)) {
            tot++;
        }
    }
    cout << tot << endl;
    
    tot = 0;
    for (int i = 1; i < 10000; i++) {
        if (iis(i)) {
            tot++;
        }
    }
    cout << tot << endl;
    
    tot = 0;
    for (int i = 1; i < 100000; i++) {
        if (iis(i)) {
            tot++;
        }
    }
    cout << tot << endl;
    
    tot = 0;
    for (int i = 1; i < 1000000; i++) {
        if (iis(i)) {
            tot++;
        }
    }
    cout << tot << endl;
}*/

int res[7] = {
    1,
    9,
    18,
    54,
    90,
    174,
    258
};

int main() {
    int ff;
    cin >> ff;
    while (ff--) {
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
}
