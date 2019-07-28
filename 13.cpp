#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int min_w=0;
int n;
vector<int> w; vector<int> p;
long long gArr[100000];

long long g(int v) {
	if (v < min_w) return 0;
	int Max=-1;
	_for(i, 0, n) {
		if (w[i] > v) continue;
		if (gArr[v - w[i]] == -7) gArr[v - w[i]]=g(v-w[i]);
		int tmp = gArr[v - w[i]]+p[i];
		if (tmp > Max) Max = tmp;
	}
	return Max;
}

int main() {

	int V;
	while (cin>>V)
	{
		w.clear(); p.clear();
		cin >> n;
		min_w = V + 1;
		_for(i, 0, 100000) {
			gArr[i] = -7;
		}

		_for(i, 0, n) {
			int cinW, cinP; cin >> cinW >> cinP;
			if (cinW < min_w) min_w = cinW;
			w.push_back(cinW);p.push_back(cinP);
		}
		cout << g(V) << "\n";
	}
	return 0;

}
