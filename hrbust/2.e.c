#include <stdio.h>
#include <queue>
using namespace std;

struct cmp1  
{
	long g;
	long num;

	cmp1() {
		this->g = 0;
		this->num = 0;
	}

	cmp1(long g, long num) {
		this->g = g;
		this->num = num;
	}

    friend bool operator < (cmp1 a, cmp1 b)
    {  
        return a.g > b.g;
    }  
};   

priority_queue<cmp1*, vector<cmp1*> , greater<cmp1*> > q;

int main() {
	long long totgold = 0;
	int n, i;
	long d;
	char c;
	scanf("%d", &n);
	getchar();
	for (i = 2; i < n; i++) {
		getchar();
		scanf("%c %ld", &c, &d);
		if (c == 'd') {
			cmp1 *aa = new cmp1(d, i);
			q.push(aa);
			totgold += d;
		} else {
			while (q.size() > d) {
				totgold -= q.top()->g;
				q.pop();
			}
		}
	}
	getchar();
	scanf("%c %ld", &c, &d);
	if (q.size() < d) {
		printf("-1\n");
	} else {
		printf("%lld\n%ld\n", totgold, q.size());
		while (q.size() > 0) {
			printf("%ld ", q.top()->num);
			q.pop();
		}
		printf("\n");
	}
}