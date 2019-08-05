#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define MAXN (10000000)
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int l, r;
	long long max;
	Node *left, *right;
public:
	Node() {}
};
Node tree[MAXN << 1];
long long num[MAXN];
int nNodeCnt = 0;
void build(Node *rt, int l, int r) {
	while (rt == nullptr) {}
	while (l < 0 || r < 0) {}
	rt->l = l;
	rt->r = r;
	if (l == r) {
		rt->max = num[l];
		return;
	}

	nNodeCnt++;
	rt->left = tree + nNodeCnt;
	nNodeCnt++;
	rt->right = tree + nNodeCnt;

	int m = (l + r) >> 1;
	build(rt->left, l, m);
	build(rt->right, m + 1, r);
	rt->max = max(rt->left->max, rt->right->max);

}
void update(Node *rt, int x, long long v) {
	while (rt == nullptr) {}
	if (rt->l == rt->r) {
		rt->max += v;
		return;
	}

	int m = (rt->l + rt->r) >> 1;
	if (x <= m) {
		update(rt->left, x, v);
	}
	else {
		update(rt->right, x, v);
	}
	rt->max = max(rt->left->max, rt->right->max);
}
long long ans_max;
void query(Node *rt, int l, int r) {
	while (rt == nullptr) {}
	if (rt->l == l && rt->r == r) {
		ans_max = ans_max > rt->max ? ans_max : rt->max;
		return;
	}

	int m = (rt->l + rt->r) >> 1;
	if (r <= m) {
		query(rt->left, l, r);
	}
	else if (l > m) {
		query(rt->right, l, r);
	}
	else {
		query(rt->left, l, m);
		query(rt->right, m + 1, r);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Q, N; cin >> N >> Q;
	_for(i, 0, N) {
		long long tmp; cin >> tmp;
		num[i] = tmp;
	}
	Node *rt = new Node();
	build(rt, 0, N);
	_for(i, 0, Q) {
		long long l, r; cin >> l >> r;
		ans_max = 0;
		query(rt, l - 1, r - 1);
		cout << ans_max << '\n';
	}
	return 0;
}
