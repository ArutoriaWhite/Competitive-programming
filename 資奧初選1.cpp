#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define pii pair<int,int>
#define INF
#include <vector>
#include <iostream>
#include <tuple>
#include <map>
using namespace std;

int N;
vector <pii> points;
map<pii, pii> linesType;
map<pii, int> linesCntr;

pii calcLine

void DFS(int u,int p) {
	_for(v,0,N) {
		if (v == p) continue;
		if (linesType.count(pii(u, v)) == 0) {
			int x=points[u].first, y=points[u].second, z=points[v].first, w=points[v].second;
		}
		if (linesType[pii(u, v)] != linesType[pii(p, u)]) continue;
		linesCntr[ linesType[pii(u, v)] ]++;
		DFS(v, u);
	}
}

int main() {
	cin >> N;
	_for(i, 0,N) {
		int x,y; cin >> x>>y;
		points.push_back(pii(x,y));
	}
	DFS(0,-1);
	return 0;
}
