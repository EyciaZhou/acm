#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string list[2005];
struct node {
	int u, v, w;
};

bool cmpa (const struct node &a, const struct node &b) {
	return a.w < b.w;
}

int fa[2005];

int getfa(int v) {
	if (fa[v] != v) {
		int k = getfa(fa[v]);
		fa[v] = k;
		return k;
	}
	return v;
}

struct node ll[4000000];
int lll;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> list[i];
		}
		lll = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					int dif = 0;
					for (int k = 0; k < 7; k++) {
						if (list[i][k] != list[j][k]) {
							dif++;
						}
					}
					lll++;
					ll[lll].u = i;
					ll[lll].v = j;
					ll[lll].w = dif;
				}
			}
		}
		sort(ll, ll+lll, &cmpa);
		for (int i = 0; i < n; i++) {
			fa[i] = i;
		}
		long pri = 0;
		for (int i = 0; i < n; i++) {
			if (getfa(ll[i].u) != getfa(ll[i].v)) {
				fa[fa[ll[i].u]] = fa[ll[i].v];
				pri += ll[i].w;
			}
		}
		cout << "The highest possible quality is 1/" << pri << ".\n";
	}
}