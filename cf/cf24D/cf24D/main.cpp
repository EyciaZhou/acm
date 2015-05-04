//
//  main.cpp
//  cf24D
//
//  Created by eycia on 14/12/26.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;

#define mat_l 1000
double mat[mat_l+5][mat_l+5];
int mat_size;
double eps=1e-8;

void g_a_o_gao_s_i_si() {
    int p_h = 0;
    for (int i = 0; i < mat_size; i++) {
        if (fabs(mat[p_h][i]) < eps) {
            for (int j = p_h+1; j < mat_size; j++) {
                if (fabs(mat[j][i]) > eps) {
                    for (int k = i; k <= mat_size; k++) {
                        swap(mat[p_h][k], mat[j][k]);
                    }
                }
            }
        }
        if (fabs(mat[p_h][i]) > eps) {
            for (int k = i+1; k < min(i+3, mat_size); k++) {
                mat[p_h][k] /= mat[p_h][i];
            }
            mat[p_h][mat_size] /= mat[p_h][i];
            mat[p_h][i] = 1;
            for (int j = p_h+1; j < min(p_h+2, mat_size); j++) {
                double rate = mat[j][i];
                if (fabs(mat[j][i]) > eps) {
                    for (int k = i; k < min(i+3, mat_size); k++) {
                        mat[j][k] -= mat[p_h][k] * rate;
                    }
                    mat[j][mat_size] -= mat[p_h][mat_size] * rate;
                }
            }
            p_h++;
        }
    }
    p_h = mat_size - 1;
    for (int i = mat_size - 1; i >= 0; i--) {
        if (fabs(mat[p_h][i]) < eps) {
            for (int j = mat_size - 1; j >= p_h+1; j--) {
                if (fabs(mat[j][i]) > eps) {
                    for (int k = 0; k <= mat_size; k++) {
                        swap(mat[p_h][k], mat[j][k]);
                    }
                }
            }
        }
        if (fabs(mat[p_h][i]) > eps) {
            for (int k = i+1; k < min(i+3, mat_size); k++) {
                mat[p_h][k] /= mat[p_h][i];
            }
            mat[p_h][mat_size] /= mat[p_h][i];
            mat[p_h][i] = 1;
            for (int j = p_h-1; j >= max(p_h-2, 0); j--) {
                double rate = mat[j][i] / mat[p_h][i];
                if (fabs(mat[j][i]) > eps) {
                    for (int k = i; k < min(i+3, mat_size); k++) {
                        mat[j][k] -= mat[p_h][k] * rate;
                    }
                    mat[j][mat_size] -= mat[p_h][mat_size] * rate;
                }
            }
            p_h--;
        }
    }
    
}
#undef mat_l

void gen_mat() {
    if (mat_size == 1) {
        mat[0][0] = 1;
        mat[0][1] += 2;
        return;
    }
    
    for (int i = 1; i < mat_size - 1; i++) {
        mat[i][mat_size] += 4;
        mat[i][i] = 3;
        mat[i][i-1] = mat[i][i+1] = -1;
    }
    mat[0][mat_size] += 3;
    mat[mat_size - 1][mat_size] += 3;
    mat[0][0] = 2;
    mat[0][1] = -1;
    mat[mat_size - 1][mat_size - 1] = 2;
    mat[mat_size - 1][mat_size - 2] = -1;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    mat_size = m;
    int ii, jj;
    cin >> ii >> jj;
    memset(mat, 0, sizeof(mat));
    
    for (int i = ii; i < n; i++) {
        gen_mat();
        g_a_o_gao_s_i_si();
    }
    printf("%.10f\n", mat[jj-1][mat_size]);
}
