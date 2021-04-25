#include <bits/stdc++.h>
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

multiset<int> s;

signed main()
{
	ShinraTensei
	int n, l, r;
	cin >> n;
	while (n--)
	{
		cin >> l >> r; r++;
		s.insert(l);
		if (s.lower_bound(r) != s.end())
			s.erase(s.lower_bound(r));
	}
	cout << s.size() << '\n';
}
