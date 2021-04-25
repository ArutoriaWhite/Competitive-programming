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
typedef vector<vector<int>> Mat;
const int N = 210;

Mat operator * (Mat p, Mat q)
{

}
int n, m, s, t;
int w[N];

signed main()
{
	cin >> n >> m >> s >> t;
	rep(i,1,n) cin >> w[i];

	Mat sw(n);
	for (auto &v: sw) v.resize(n);

	while (m--)
	{
		int u, v;
		cin >> u >> v, u--, v--;
		sw[u][v] = 1;
	}
	
	Mat res(n);	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			res[i].pb(j==i);
}
