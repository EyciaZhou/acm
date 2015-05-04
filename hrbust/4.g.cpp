#include <stdio.h>

int src[250005], dst[250005], next[250005];

int main() {
	int n, m;
	char ch;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int temp = 0;
		getchar();
		for (int j = 0; j < 8; j++) {
			temp *= 2;
			ch = getchar();
			if (ch == '1') {
				temp += 1;
			}
		}
		src[i] = temp;
	}
	for (int i = 0; i < m; i++) {
		int temp = 0;
		getchar();
		for (int j = 0; j < 8; j++) {
			temp *= 2;
			ch = getchar();
			if (ch == '1') {
				temp += 1;
			}
		}
		dst[i] = temp;
	}
	next[0] = -1;
	for (int i = 1, j = -1; i < m; i++) {
		while (j > 0 && dst[j + 1] / 2 != dst[i] / 2) {
			j = next[j];
		}
		if (dst[j+1] / 2 == dst[i] / 2) {
			j++;
		}
		next[i] = j;
	}
	long min = 10000000;
	long pos = 0;
	for (int i = 0, j = -1; i < n;i++) {
		while (j >= 0 && src[i] / 2 != dst[j+1] / 2) {
			j = next[j];
		}
		if (src[i] / 2 == dst[j+1] / 2) {
			j++;
		}
		if (j == m - 1) {
			long diff = 0;
			for (int k = 0; k < m; k++) {
				diff += src[i - k] ^ dst[j - k];
			}
			if (diff < min) {
				min = diff;
				pos = i - m + 1;
			}
			j = next[j];
		}
	}
	if (min == 10000000) {
		printf("No\n");
	} else {
		printf("Yes\n%ld %ld", min, pos+1);
	}
}