#include <iostream>
#define MAX_TERMS 101
using namespace std;

typedef struct {
	int c;
	int r;
	int v;
} term;

void matrix_read(term *mtx) {
	int x, y, t, k;
	cin >> x >> y;
	k = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> t;
			if (t) { 
				mtx[++k].v = t;
				mtx[k].c = i;
				mtx[k].r = j;
			}
		}
	}
	mtx[0].c = x;
	mtx[0].r = y;
	mtx[0].v = k;
}

void matrix_print(term *a) {
	int x, y = 0;
	int k = 1;
	for (int i = 0; i < a[0].c; i++) {
		for (int j = 0; j < a[0].r; j++) {
			if (a[k].c == i && a[k].r == j) {
				cout << a[k].v << "	";
				k++;
			} else {
				cout << 0 << "	";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void matrix_transpose(term *a, term *b) {
	int r[a[0].r + 1];
	for (int i = 0; i <= a[0].r; i++) {
		r[i] = 0;
	}
	r[0] = 1;
	for (int i = 1; i <= a[0].v; i++) {
		r[a[i].r + 1]++;
	}
	for (int i = 1; i <= a[0].r; i++) {
		r[i] = r[i - 1] + r[i];
	}
	for (int i = 1; i <= a[0].v; i++) {
		int j = r[a[i].r]++;
		b[j].c = a[i].r;
		b[j].r = a[i].c;
		b[j].v = a[i].v;
	}
	b[0].r = a[0].c;
	b[0].c = a[0].r;
	b[0].v = a[0].v;
}

int cmp(term x, term y) {
	if (x.c > y.c) {
		return 1;
	}
	if (x.c < y.c) {
		return -1;
	}
	if (x.r > y.r) {
		return 1;
	}
	if (x.r < y.r) {
		return -1;
	}
	return 0;
}

bool matrix_muti(term *a, term *b, term *c) {
	
}

bool matrix_add(term *a, term *b, term *c) {
	if (a[0].c != b[0].c || a[0].r != b[0].r) {
		return false;
	}
	int x = 1, y = 1;
	int k = 0;
	cout << x << "  " << a[0].v << "  " << y << "  " << b[0].v << endl;
	while (x <= a[0].v && y <= b[0].v) {
		k++;
		switch (cmp(a[x], b[y])) {
			case -1:
				c[k].c = a[x].c;
				c[k].r = a[x].r;
				c[k].v = a[x].v;
				x++;
				break;
			case 0:
				c[k].c = a[x].c;
				c[k].r = a[x].r;
				c[k].v = a[x].v + b[y].v;
				x++;
				y++;
				break;
			case 1:
				c[k].c = b[y].c;
				c[k].r = b[y].r;
				c[k].v = b[y].v;
				y++;
				break;
		}
	}
	for (; x <= a[0].v; x++) {
		k++;
		c[k].c = a[x].c;
		c[k].r = a[x].r;
		c[k].v = a[x].v;
	}
	for (; y <= b[0].v; y++) {
		k++;
		c[k].c = b[y].c;
		c[k].r = b[y].r;
		c[k].v = b[y].v;
	}
	c[0].c = a[0].c;
	c[0].r = a[0].r;
	c[0].v = k;
}

void _print(term *a) {
	for (int i = 0; i <= a[0].v; i++) {
		cout << a[i].c << "	" << a[i].r << "	" << a[i].v << "	" << endl;
	}
	cout << endl;
}

int main() {
	term a[100];
	term b[100];
	term c[100];
	matrix_read(a);
	matrix_transpose(a, b);
	matrix_add(a, b, c);
	matrix_print(a);
	matrix_print(b);
	matrix_print(c);
	_print(a);
	_print(b);
	_print(c);
}
