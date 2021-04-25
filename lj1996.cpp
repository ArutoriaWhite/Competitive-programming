#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

list<int> L;
int n, m;

signed main()
{
	cin >> n >> m;
	rep(i,1,n) L.push_back(i);
	auto it = L.begin();
	while (L.size())
	{
		rep(i,1,m-1)
			it++, it=(it==L.end()? L.begin() : it);
		cout << *it << ' ';
		L.erase(it++);
		it=(it==L.end()? L.begin() : it);
	}
	cout << endl;
}
