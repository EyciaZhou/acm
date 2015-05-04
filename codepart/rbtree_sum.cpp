#include <iostream>
using namespace std;
#define RED true
#define BLACK false

struct Tree {
	int sum;	//该节点下（包括）所有节点之和
	int ns;		//该节点下（包括）节点数
	int v;		//该节点的值
	bool c;		//该节点的颜色
	Tree *lc, *rc;	//左右儿子
	Tree *p;		//父亲节点
};
typedef Tree *pTree;

void tj(Tree *t) {
	//计算该节点的ns与sum（不递归）
	t->ns = 1;
	t->sum = t->v;
	if (t->lc) {
		t->ns += t->lc->ns;
		t->sum += t->lc->sum;
	}
	if (t->rc) {
		t->ns += t->rc->ns;
		t->sum += t->rc->sum;
	}
}

void left_rota(Tree *t) {
	Tree *p = t->p;
	Tree *a = t;
	Tree *b = t->rc;
	Tree *c = t->rc->lc;
	
	if (p) {
		if (p->lc == t) {
			p->lc = b;
		}else{
			p->rc = b;
		}
	}
	b->p = p;
	
	t->p = b;
	b->lc = a;
	if (c) {
		c->p = a;
	}
	a->rc = c;
	tj(a);
	tj(b);
}

void right_rota(Tree *t) {
	Tree *p = t->p;
	Tree *a = t;
	Tree *b = t->lc;
	Tree *c = t->lc->rc;
	

	if (p) {
		if (p->lc == t) {
			p->lc = b;
		}else{
			p->rc = b;
		}
	}
	b->p = p;

	t->p = b;
	b->rc = a;

	if (c) {
		c->p = a;
	}
	a->lc = c;
	tj(a);
	tj(b);
}

void pptree(Tree *t) {
	if (!t) {
		return ;
	}
	cout << t->v << "|" << t->c;
	if (t->lc || t->rc) {
		cout << " (";
		pptree(t->lc);
		cout << "),(";
		pptree(t->rc);
		cout << ")";
	}
}

int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int GetNoN(Tree *t, int n) {
	Tree *x = t;
	int ln = 0;
	while (x) {
		if (x == NULL) {
			return 0;
		}
		ln = 0;
		if (x->lc) {
			ln = x->lc->ns;
		}
		if (n == ln + 1) {
			return x->v;
		}
		if (n <= ln) {
			x = x->lc;
		}else{
			n = n - ln - 1;
			x = x->rc;
		}
	}
}

int GetSum(Tree *t, int s, int e) {
	if (t == NULL) {
	cout << "GetSum:" << s << " " << e << " Gets " << 0 <<endl;
		return 0;
	}
	if (s == 1 && e == t->ns) {
	cout << "GetSum:" << s << " " << e << " Gets " << t->sum <<endl;
		return t->sum;
	}
	int tot = 0;
	int ln = 0;
	(t->lc) && (ln = t->lc->ns);
	if (s <= ln + 1) {
		tot += t->v;
	}
	if ((t->lc) && (s <= ln)) {
		tot += GetSum(t->lc, s, min(ln, e));
	}
	if (t->rc && e >= ln + 2) {
		tot += GetSum(t->rc, max(1, s-ln-1), e-ln-1);
	}
	cout << "GetSum:" << s << " " << e << " Gets " << tot <<endl;
	return tot;
}

pTree Insert(Tree *tree, int v) {
	//Insert And Set The New Point RED
	Tree *x = tree;
	Tree *pp = NULL; // x's Father
	while (x) {
		pp = x;
		x->sum += v;
		x->ns++;
		if (v < x->v) {
			x = x->lc;
		}else{
			x = x->rc;
		}
	}
	x = new Tree;
	x->ns = 1;
	x->sum = v;
	x->p = pp;
	x->v = v;
	x->c = RED;
	x->lc = NULL;
	x->rc = NULL;
	if (pp) {
		if (pp->v > x->v) {
			pp->lc = x;
		}else{
			pp->rc = x;
		}
	}
	//Modify
	while (x->p && x->p->c) {
		if (x->p->p->lc == x->p) { //Because Of the Color of Root Is Black, When x's Father Is Red, x has Grandfather.
			if (x->p->p->rc && x->p->p->rc->c) {
				x->p->p->c = RED;
				x->p->c = BLACK;
				x->p->p->rc->c = BLACK;
				x = x->p->p;
			}else{
				if (x->p->rc == x) {
					left_rota(x->p);
					x = x->lc;
				}
				right_rota(x->p->p);
				x->p->c = BLACK;
				x->p->rc->c = RED;
			}
		}else{
			if (x->p->p->lc && x->p->p->lc->c) {
				x->p->p->c = RED;
				x->p->c = BLACK;
				x->p->p->lc->c = BLACK;
				x = x->p->p;
			}else{
				if (x->p->lc == x) {
					right_rota(x->p);
					x = x->rc;
				}
				pptree(x->p->p->p);
				cout << endl;
				left_rota(x->p->p);
				pptree(x->p);
				cout << endl;
				x->p->c = BLACK;
				x->p->lc->c = RED;
			}
		}
	}
	for (; x->p; x = x->p);
	x->c = BLACK;
	pptree(x);
	cout << endl;
	return x;
}

int main() {
	Tree *t = NULL;
	int k;
	int s, e;
	for (int i = 0; i< 10; i++) {
		cin >> k;
		t = Insert(t, k);
	}
	while (1) {
	cin >> s;
	cout << GetNoN(t, s) << endl;
	}
	return 0;
}
