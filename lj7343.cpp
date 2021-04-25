#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define endl '\n'
#define ff first
#define ss second
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 5e5+10;

vector<int> l;
int a[N], n, m;

signed main()
{
	pui
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	l.resize(m);
	for (int i=0; i<m; i++) cin >> l[i];
	l.pb(0), l.pb(n);
	sort(l.begin(), l.end());

	for (int i=0; i<l.size()-1; i++)
	{
		sort(a+l[i], a+l[i+1]);
	}
	
	for (int i=0; i<n; i++) cout << a[i] << ' ';
}
