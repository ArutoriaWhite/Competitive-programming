#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int s, d, T;
	cin >> T;
	while (T--)
	{
		cin >> s >> d;
		if ((s+d)&1 || s<d) cout << "impossible\n";
		else cout << ((s+d)>>1) << ' ' << (s-((s+d)>>1)) << '\n';
	}
	return 0;
}

