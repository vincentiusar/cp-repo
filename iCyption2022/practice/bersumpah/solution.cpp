#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define g(x,y) *(ar + x * h + y)
#define pb push_back
#define pob pop_back
#define binser binary_search

string tar, s;
int n,k;

struct node{
	int pred, c;
	string kata;
}; 
node x;
queue<node> q;

struct nod {
	string data;
	struct nod *r;
	struct nod *l;
};

nod *root;
nod* newnode(string s) {
	nod *get = new nod;
	get->data = s;
	get->r = NULL;
	get->l = NULL;
	return (get);
}

bool pain(string kal) {
	nod *f = root; 
	while (f != NULL) {
		if (f->data == kal) return true;
		if (f->data < kal) { 
			if (f->r == NULL) {
				f->r = newnode(kal);
				return false;
			} else {
				f = f->r;
			}
		} else if (f->data > kal) {
			if (f->l == NULL) {
				f->l = newnode(kal);
				return false;
			} else {
				f = f->l;
			}
		}
	}
}


int main() {

	cin >> s >> tar >> k;
	x = {-1, 0, s};
	n = s.length();
	q.push(x);
	root = newnode(s);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		s = x.kata;
		if (s == tar) {
			cout << "BISA\n";
			return 0;
		}

		for (int i = 0; i <= n-k; ++i) {
			if (i == x.pred) continue;
			s = x.kata;
			string tmp = s.substr(i,k);
			reverse(tmp.begin(), tmp.end());
			s.replace(i, k, tmp);

			if (!pain(s)) {
				if (s == tar) {
					cout << "BISA\n";
					return 0;
				}
				q.push({i,x.c+1,s});
			}
		}
	}
	cout << "TIDAK\n";
}