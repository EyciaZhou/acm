#include <iostream>
#include <map>
#include <string.h>
#include <stdio.h>
using namespace std;

char s1[10005];
char s2[10005];
int f[2][10005];
map<char, int> m;

int main() {
	char c[2];
	int v;
	int n;
	int l1, l2;
	while (scanf("%d", &n) != EOF) {
		m.clear();
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; i++) {
			getchar();
			scanf("%s %d", c, &v);
			m[c[0]] = v;
		}
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		l1 = strlen(s1 + 1);
		l2 = strlen(s2 + 1);

		for (int ii = 1; ii <= l1; ii++) {
			int i = ii % 2;
			for (int j = 1; j <= l2; j++) {
				if (s1[ii] == s2[j]) {
					f[i][j] = f[(i+1)%2][j-1] + m[s1[ii]];
				} else {
					f[i][j] = f[(i+1)%2][j] > f[i][j-1] ? f[(i+1)%2][j] : f[i][j-1];
				}
			}
		}

		printf("%d\n", f[(l1)%2][l2]);
	}
}