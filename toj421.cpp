#define _for(i,a,b) for(int i=(a);i<(b);i++)
#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr;

long long g(int l, int r) {

}

int main() {
	int N, Q; cin >> N >> Q;
	_for(i, 0, N) {
		long long cinTmp; cin >> cinTmp;
		arr.push_back(cinTmp);
	}
	_for(i, 0, Q) {
		int l, r; cin >> l, r;
		cout << g(l, r);
	}


}
