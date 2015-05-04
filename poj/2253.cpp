#include <iostream>
#include <iomanip>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

long n;

long long max(long long a, long long b){
	if (a > b) {
		return a;
	}
	return b;
}

long long spfa() {
	vector<pair<long long, long long> > poss;
	long long f, s;
	for (int i = 0; i < n; i++) {
		cin >> f >> s;
		poss.push_back(make_pair(f, s));
	}
	bool v[205];
	memset(v, sizeof(v), false);
	v[0] = true;
	long long dis[205];
	for (int i = 0; i < n; i++) {
		dis[i] = -1;
	}
	dis[0] = 0;
	queue<int> *q = new queue<int>();
	q->push(0);
	while (!q->empty()) {
		long k = q->front();
		q->pop();

		v[k] = false;
		for (int i = 0; i < n; i++) {
			if (i != k) {
				double temp = max(pow(poss[i].first - poss[k].first, 2) + pow(poss[i].second - poss[k].second, 2), dis[k]);
				if (dis[i] < 0 || temp < dis[i]) {
					dis[i] = temp;
					q->push(i);
					v[i] = true;
				}
			}
		}
	}
	return dis[1];
}

int main() {
	long k = 0;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		printf("Scenario #%ld\nFrog Distance = %.3f\n\n", ++k, sqrt(spfa()));
	}
}