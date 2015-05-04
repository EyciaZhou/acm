long long c[55][55];

void genc() {
    memset(c, 0, sizeof(c));
    c[1][1] = 1;
    for (int i = 2; i <= 54; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }
    for (int i = 1; i <= 54; i++) {
        for(int j = 1; j <= i; j++) {
            c[i-1][j-1] = c[i][j];
        }
    }
}