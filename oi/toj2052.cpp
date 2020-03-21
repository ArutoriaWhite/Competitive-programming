#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define OnlyMyRailGun ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

string x,y;
int d, res;

int main()
{
	OnlyMyRailGun;
	cin >> d;
	cin >> x, y=x;
	sort(x.begin(),x.end());
	while (x!=y)
	{
		next_permutation(x.begin(),x.end());
		res = (res+1)%d;
	}
	cout << res << '\n';
}
