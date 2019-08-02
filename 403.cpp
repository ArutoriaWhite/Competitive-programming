#define _vec pair<int,int>
#define _vecPlus(v,x,y) _vec(v.first+x,v.second+y)
#define _atV(v) [v.second][v.first]
#define _atPos(x,y) [y][x]
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <limits.h>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int G[22][22];
int H, W, X, Y;
_vec target;
enum Forward {_E,_S,_W,_N};

int DP(_vec u, Forward f) {
	if (G _atV(u) == INT_MAX) return INT_MAX;
	if (u == target) return G _atV(u);
	int tmp = G _atV(u);
	G _atV(u) = INT_MAX;
	int r;
	switch (f)
	{
	case _N:
		r= tmp + min(0, min(DP(_vecPlus(u, 0, -1), _N)
			,DP(_vecPlus(u, -1, 0), _W)));
		G _atV(u) = tmp;
		return r;
		break;
	case _S:
		r= tmp + min(0,min(DP(_vecPlus(u, 0, 1), _S)
			, DP(_vecPlus(u, 1, 0), _E),0));
		G _atV(u) = tmp;
		return r;
		break;
	case _W:
		r= tmp + min(0,min(DP(_vecPlus(u, -1, 0), _W)
			, DP(_vecPlus(u, 0, 1), _S),0));
		G _atV(u) = tmp;
		return r;
		break;
	case _E:
		r= tmp + min(0,min(DP(_vecPlus(u, 1, 0), _E)
			, DP(_vecPlus(u, 0, -1), _N),0));
		G _atV(u) = tmp;
		return r;
		break;
	}
}

int main() {
	cin >> H >> W >> X >> Y;
	target = _vec(X, Y);
	_for(y, 1, H + 1) {
		_for(x, 1, W + 1) {
			int tmp; cin >> tmp;
			G _atPos(x,y) = tmp;
		}
	}
	_for(x, 0, W + 2) G _atPos(x,0) = G _atPos(x,H+1) = INT_MAX;
	_for(y, 0, H + 2) G _atPos(0, y) = G _atPos(W + 1, y) = INT_MAX;
	cout<<DP(_vec(1, 1), _S)<<"\n";
	return 0;
}
