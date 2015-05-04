#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <stdio.h>
using namespace std;

int mmap[55][55];
vector<pair<int, int> > ali;
map<pair<int, int>, int> ref;

long m[105][105];

bool v[105];
long dis[105];

int stepx[4] = {0, 1, -1, 0};
int stepy[4] = {1, 0, 0, -1};

void bfs(int node) {
	queue<pair<int, int> > q;
	int v[55][55];
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			v[i][j] = -1;
		}
	}
	v[ali[node].first][ali[node].second] = 0;
	q.push(ali[node]);
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		if (mmap[temp.first][temp.second] == -1) {
			continue;
		}
		if (mmap[temp.first][temp.second] == 1) {
			m[node][ref[temp]] = v[temp.first][temp.second];
		}
		for (int i = 0; i < 4; i++) {
			if (v[temp.first+stepx[i]][temp.second+stepy[i]] < 0) {
				v[temp.first+stepx[i]][temp.second+stepy[i]] = v[temp.first][temp.second] + 1;
				q.push(make_pair(temp.first+stepx[i], temp.second+stepy[i]));
			}
		}
	}
}

int main() {
	int ff;
	char c;
	cin >> ff;
	for (int i = 0; i < ff; i++) {
		int nn, mm;
		cin >> nn >> mm;
		ali.clear();
		for (int i = 0; i <= mm + 1; i++) {
			for (int j = 0; j <= nn + 1; j++) {
				mmap[i][j] = -1;
			}
		}
		while (getchar() != '\n') {
		}
		for (int i = 1; i <= mm; i++) {
			for (int j = 1; j <= nn; j++) {
				c = getchar();
				if (c == 'A' || c == 'S') {
					pair<int, int> temp = make_pair(i, j);
					ref[temp] = ali.size();
					ali.push_back(temp);
				}
				if (c == 'A' || c == 'S') {
					mmap[i][j] = 1;
				}
				if (c == ' ') {
					mmap[i][j] = 0;
				}
				if (c == '#') {
					mmap[i][j] = -1;
				}
			}
			getchar();
		}
		for (int i = 0; i < ali.size(); i++) {
			bfs(i);
		}

		memset(v, false, sizeof(v));
		memset(dis, 0, sizeof(dis));
		v[0] = true;
		int tot = 1;
		int res = 0;
		for (int i = 0; i < ali.size(); i++) {
			dis[i] = m[0][i];
		}
		while (tot < ali.size()) {
			long min = 1000000000;
			long dst = 0;
			for (int i = 0; i < ali.size(); i++) {
				if (!v[i] && dis[i] < min) {
					min = dis[i];
					dst = i;
				}
			}
			v[dst] = true;
			tot++;
			res += min;
			
			for (int i = 0; i < ali.size(); i++) {
				if (!v[i] && dis[i] > m[dst][i]) {
					dis[i] = m[dst][i];
				}
			}
		}
		cout << res << endl;
	}
}