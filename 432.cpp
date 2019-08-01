#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define vec pair<int,int>
#include <tuple>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

bool G[1000][1000];
int N, M;
bool isOut=false;
vec me;
vec target;

void BFS(vec u) {
	queue<vec> q;
	q.push(u);

	while (q.size()>0){
		vec v = q.front(); q.pop();
		if (v == target) {
			isOut = true;
			return;
		}
		if (!G[v.second + 1][v.first]) q.push(vec(v.second + 1, v.first));
		if (!G[v.second][v.first + 1]) q.push(vec(v.second, v.first + 1));
		if (!G[v.second - 1][v.first]) q.push(vec(v.second - 1, v.first));
		if (!G[v.second][v.first - 1]) q.push(vec(v.second, v.first - 1));
		G[v.second][v.first] = true;
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	_for(y, 1, M+1) {
		_for(x, 1, N+1) {
			G[y][x] = false;
		}
	}
	int Xme, Yme; cin >> Xme >> Yme;
	me = vec(Xme, Yme);
	int xt, yt; cin >> xt >> yt;
	target=vec(xt,yt);

	int f; cin >> f;
	_for(i, 0, f) {
		int x, y; cin >> x >> y;
		G[y][x] = true;
	}
	BFS(me);
	if (isOut) cout << "Cool!\n";
	else cout << "Harakiri!\n";
	return 0;
}
