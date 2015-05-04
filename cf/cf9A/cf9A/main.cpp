//
//  main.cpp
//  cf9A
//
//  Created by eycia on 14/12/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    int a = max(n, m);
    switch (a) {
        case 1:
            cout << "1/1" << endl;
            break;
        case 2:
            cout << "5/6" << endl;
            break;
        case 3:
            cout << "2/3" << endl;
            break;
        case 4:
            cout << "1/2" << endl;
            break;
        case 5:
            cout << "1/3" << endl;
            break;
        case 6:
            cout << "1/6" << endl;
            break;
    }
}
