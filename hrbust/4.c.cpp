#include <stdio.h>
#include <stdlib.h>

struct node {
	int next;
	int prev;
	long le;
} nod[500005];

int link[500005];

int main() {
	int n, m;
	int no;
	long ll;
	char op[30];
	scanf("%d %d", &n, &m);
	long num = 1;
	long mem = -1;
	mem++;
	nod[mem].le = -1;
	nod[mem].next = -1;
	nod[mem].prev = -1;
	link[1] = mem;
	for (int i = 0; i < n; i++) {
		scanf("%s %d", op, &no);
		if (op[0] == 'l') {
			scanf("%ld", &ll);
			mem++;
			nod[mem].le = ll;
			nod[mem].next = -1;
			nod[mem].prev = link[no];
			nod[link[no]].next = mem;
			link[no] = mem;
		}
		if (op[0] == 'r' && op[1] == 'o') {
			mem++;
			nod[mem].le = nod[nod[link[no]].prev].le;
			nod[mem].prev = nod[nod[link[no]].prev].prev;
			nod[mem].next = nod[nod[link[no]].prev].next;
			link[no] = mem;
		}
		if (op[0] == 'r' && op[1] == 'e') {
			mem++;
			nod[mem].le = nod[nod[link[no]].next].le;
			nod[mem].prev = nod[nod[link[no]].next].prev;
			nod[mem].next = nod[nod[link[no]].next].next;
			link[no] = mem;
		}
		if (op[0] == 'c' && op[1] == 'l') {
			mem++;
			nod[mem].le = nod[link[no]].le;
			nod[mem].next = nod[link[no]].next;
			nod[mem].prev = nod[link[no]].prev;
			link[++num] = mem;
		}
		if (op[0] == 'c' && op[1] == 'h') {
			if (link[no] == -1 || nod[link[no]].le == -1) {
				printf("basic\n");
			}else {
				printf("%ld\n", nod[link[no]].le);
			}
		}
	}
}