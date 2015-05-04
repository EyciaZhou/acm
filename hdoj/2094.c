#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool hashtb[3123];
char hashmp[3123][100];
int in[3123];

int hash(char *st) {
	int tot = 0;
	int i;
	for (i = 0; i < strlen(st); i++) {
		tot = (tot + st[i]) % 3123;
	}
	while (hashtb[tot]) {
		if (strcmp(st, hashmp[tot]) == 0) {
			return tot;
		}
		tot = (tot + 1) % 3123;
	}
	hashtb[tot] = true;
	strcpy(hashmp[tot], st);
	return tot;
}

int main() {
	int n, ib, i;
	char a[100], b[100];
	while (true) {
		memset(in, 0, sizeof(in));
		memset(hashtb, false, sizeof(hashtb));
		memset(hashmp, 0, sizeof(hashmp));
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		while (n--) {
			scanf("%s %s", a, b);
			hash(a);
			ib = hash(b);
			in[ib] += 1;
		}
		bool f = false;
		for (i = 0; i < 3123; i++) {
			if (hashtb[i] && in[i] == 0) {
				f = !f;
				if (!f) {
					break;
				}
			}
		}
		if (f) {
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}