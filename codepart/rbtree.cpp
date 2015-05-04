#include <iostream>
using namespace std;
#define RED true
#define BLACK false

struct Tree {
	int v;
	bool c;
	Tree *lc, *rc;
	Tree *p;
};
typedef Tree *pTree;

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

pTree Insert(Tree *tree, int v) {
	//Insert And Set The New Point RED
	Tree *x = tree;
	Tree *pp = NULL; // x's Father
	while (x) {
		pp = x;
		if (v < x->v) {
			x = x->lc;
		}else{
			x = x->rc;
		}
	}
	x = new Tree;
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
	for (int i = 0; i< 10; i++) {
		cin >> k;
		t = Insert(t, k);
	}
	return 0;
}
