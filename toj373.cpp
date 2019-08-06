#define _for(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define vec pair<int,int>
#define _x .first
#define _y .second
#include <tuple>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vec points[5],ch[5];

int cpm(const void *a, const void *b) {
	vec i = *(vec *)a;	vec j = *(vec*)b;
	return (i _x == j _x) ? (i _y - j _y) : (i _x - j _x);
}
int cross(vec &o, vec &a, vec &b) {
	a _x -= o _x; b _x -= o _x;
	a _y -= o _y; b _y -= o _y;
	return (a _x*b _y) - (a _y*b _x);
}
int length(vec &a, vec &b) {
	return (a _x - b _x)*(a _x - b _x) + (a _y - b _y)*(a _y - b _y);
}

void Graham () {
	qsort(points, 5, sizeof(points[0]), cpm);
	int m = 0;
	_for(i, 0, 5) {
	}
}
int main() {
	int x1, y1, x2, y2,x,y; cin >> x1 >> y1 >> x2 >> y2>>x>>y;
	points[0] = vec(x1, y1);
	points[1] = vec(x1, y2);
	points[2] = vec(x2, y2);
	points[3] = vec(x2, y1);
	points[4] = vec(x, y);
	


	return 0;
}
