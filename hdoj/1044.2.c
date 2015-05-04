#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int stepi[4] = {0, 0, 1, -1};
int stepj[4] = {1, -1, 0, 0};

int ww, hh, k, mm, d;
long l, jewp[11], dis[15][15];
bool wall[55][55];
int jewi[13], jewj[13];
long result;
bool v[15];
long t2;

void dfs(int nownode, int res, long jew, int c) {
	if (result == t2) {
		return;
	}
	if (res > l) {
		return;
	}
	if (nownode == mm + 1) {
		if (result == -1) {
			result = jew;
		}
		if (jew > result) {
			result = jew;
		}
	}
	int i;
	for (i = 0; i <= mm + 1; i++) {
		if (!v[i] && dis[nownode][i] > 0) {
			v[i] = true;
			dfs(i, res + dis[nownode][i], jew + jewp[i], c+1);
			v[i] = false;
		}
	}
}

void bfs(int nownode) {
	long map[55][55];
	int i, j;
	for (i = 0; i < 55; i++) {
		for (j = 0; j < 55; j++) {
			map[i][j] = -1;
		}
	}
	map[jewi[nownode]][jewj[nownode]] = 0;
	int head = 0, tt = 0, si, sj, ssi, ssj;
	int lli[30000];
	int llj[30000];
	lli[0] = jewi[nownode];
	llj[0] = jewj[nownode];
	while ((head + 1) % 30000 != tt) {
		si = lli[tt];
		sj = llj[tt];
		if (map[si][sj] > l) {
			break;
		}
		tt = (tt + 1) % 30000;
		for (i = 0; i < 4; i++) {
			ssi = si + stepi[i];
			ssj = sj + stepj[i];
			if (wall[ssi][ssj] || map[ssi][ssj] >= 0) {
				continue;
			}
			head = (head + 1) % 30000;
			lli[head] = ssi;
			llj[head] = ssj;
			map[ssi][ssj] = map[si][sj] + 1;
		}
	}
	for (i = 0; i <= mm + 1; i++) {
		dis[nownode][i] = map[jewi[i]][jewj[i]];
	}
}

int main() {
	int ff;
	scanf("%d\n", &d);
	for (ff = 1; ff <= d; ff++) {
		int i, j;
		char c;
		if (ff != 1) {
			printf("\n");
		}
		memset(jewp, 0, sizeof(jewp));
		scanf("%d %d %ld %d\n", &ww, &hh, &l, &mm);
		for (i = 0; i < mm; i++) {
			scanf("%ld", &jewp[i]);
		}
		memset(wall, false, sizeof(wall));
		for (i = 1; i <= hh; i++) {
			wall[i][0] = true;
			wall[i][ww + 1] = true;
		}
		for (j = 1; j <= ww; j++) {
			wall[0][j] = true;
			wall[hh + 1][j] = true;
		}
		for (i = 1; i <= hh; i++) {
			getchar();
			for (j = 1; j <= ww; j++) {
				c = getchar();
				if (c == '*') {
					wall[i][j] = true;
				}
				if (c >= 'A' && c <= 'J') {
					jewi[c - 'A'] = i;
					jewj[c - 'A'] = j;
				}
				if (c == '@') {
					jewi[mm] = i;
					jewj[mm] = j;
				}
				if (c == '<') {
					jewi[mm + 1] = i;
					jewj[mm + 1] = j;
				}
			}
		}
		printf("Case %d:\n", ff);
		bfs(mm + 1);
		if (dis[mm+1][mm] < 0 || dis[mm+1][mm] > l) {
			printf("Impossible\n");
			continue;
		}
		t2 = 0;
		for (i = 0; i < mm; i++) {
			if (dis[mm+1][i] > 0) {
				t2 += jewp[i];
			}
		}
		for (i = 0; i <= mm; i++) {
			bfs(i);
		}
		long tot = 0;
		for (i = 1; i <= mm + 1; i++) {
			if (dis[i][i-1] > 0) {
				tot += dis[i][i-1];
			}
		}
		if (tot < l) {
			l = tot;
		}
		result = -1;
		memset(v, false, sizeof(v));
		v[mm] = true;
		dfs(mm, 0, 0, 0);
		if (result == -1) {
			printf("Impossible\n");
		}else{
			printf("The best score is %ld.\n", result);
		}
	}
}