//
//  main.cpp
//  gd4
//
//  Created by eycia on 14/11/9.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;

int ski[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int skj[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int sti[4] = {1, -1, 0, 0};
int stj[4] = {0, 0, 1, -1};

int sbi[4] = {1, 1, -1, -1};
int sbj[4] = {1, -1, 1, -1};

int sni[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int snj[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int spi[2] = {1, 1};
int spj[2] = {1, -1};

char mm[9][9];

bool inside(int ii, int jj) {
    if (ii >= 0 && ii < 8 && jj >= 0 && jj < 8) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        int n;
        char a, b, c, d;
        scanf("%d", &n);
        memset(mm, 0, sizeof(mm));
        for (int i = 0; i < n; i++) {
            getchar();
            scanf("%c%c%c%c", &a, &b, &c, &d);
            mm[a-'A'][b-'1'] = d;
        }
            int tot = 0;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    switch (mm[i][j]) {
                        case 'K':
                            for (int k = 0; k < 8; k++) {
                                if (inside(i+ski[k], j+skj[k])) {
                                    if (mm[i+ski[k]][j+skj[k]] > 0) {
                                        tot ++;
                                    }
                                }
                            }
                            break;
                        case 'Q':
                            for (int k = 0; k < 8; k++) {
                                for (int l = 1; l <= 8; l++) {
                                    if (!inside(i+l*ski[k], j+l*skj[k])) {
                                        break;
                                    }
                                    if (mm[i+l*ski[k]][j+l*skj[k]] > 0) {
                                        tot ++;
                                        break;
                                    }
                                }
                            }
                            break;
                        case 'R':
                            for (int k = 0; k < 4; k++) {
                                for (int l = 1; l <= 8; l++) {
                                    if (!inside(i+l*sti[k], j+l*stj[k])) {
                                        break;
                                    }
                                    if (mm[i+l*sti[k]][j+l*stj[k]] > 0) {
                                        tot ++;
                                        break;
                                    }
                                }
                            }
                            break;
                        case 'B':
                            for (int k = 0; k < 4; k++) {
                                for (int l = 1; l <= 8; l++) {
                                    if (!inside(i+l*sbi[k], j+l*sbj[k])) {
                                        break;
                                    }
                                    if (mm[i+l*sbi[k]][j+l*sbj[k]] > 0) {
                                        tot ++;
                                        break;
                                    }
                                }
                            }
                            break;
                        case 'N':
                            for (int k = 0; k < 8; k++) {
                                if (inside(i+sni[k], j+snj[k])) {
                                    if (mm[i+sni[k]][j+snj[k]] > 0) {
                                        tot ++;
                                    }
                                }
                            }
                            break;
                        case 'P':
                            for (int k = 0; k < 2; k++) {
                                if (inside(i+spi[k], j+spj[k])) {
                                    if (mm[i+spi[k]][j+spj[k]] > 0) {
                                        tot ++;
                                    }
                                }
                            }
                            break;
                    }
                }
            }
            cout <<"Case #" << tt << ": " << tot << endl;
        }
}
