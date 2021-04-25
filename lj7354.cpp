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

int T, n, m, x, y;

signed main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> x >> y;
		int a = (x==n || x==1);
		int b = (y==m || y==1);
		if (a && b) cout << 2 << endl;
		else if (a || b) cout << 3 << endl;
		else cout << 4 << endl;
	}
}

