#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _vec pair<int,int>
#define _at(p) [p.second][p.first]
#define _vecPlus(v,x,y) (_vec(v.first+x,v.second+y))
#include <tuple>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>
#include <queue>
using namespace std;

int G[1002][1002];
int N, M;
bool canOut = false;
stack<_vec> q;
_vec me;
_vec target;

void DFS(_vec u) {
	G _at(u) = true;
	if (u == target) canOut = true;
	if (!G _at(_vecPlus(u, 1, 0))) DFS(_vecPlus(u, 1, 0));
	if (!G _at(_vecPlus(u, -1, 0))) DFS(_vecPlus(u, -1, 0));
	if (!G _at(_vecPlus(u, 0, 1))) DFS(_vecPlus(u, 0, 1));
	if (!G _at(_vecPlus(u, 0, -1))) DFS(_vecPlus(u, 0, -1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	_for(y, 0, M + 2) G[y][0] = G[y][N + 1] = true;
	_for(x, 0, N + 2) G[0][x] = G[M + 1][x] = true;
	_for(y, 1, M + 1) {
		_for(x, 1, N + 1) {
			G[y][x] = false;
		}
	}
	int x, y; cin >> x >> y;
	me = _vec(x, y);
	int xt, yt; cin >> xt >> yt;
	target = _vec(xt, yt);

	int f; cin >> f;
	_for(i, 0, f) {
		int x, y; cin >> x >> y;
		G[y][x] = true;
	}
	DFS(me);
	if (canOut) cout << "Cool!\n";
	else cout << "Harakiri!\n";
	return 0;
}
