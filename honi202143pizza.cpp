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

const int N = 110;

int pat[N], n, m, ans;

signed main()
{
	cin >> n;
	rep(i,1,n) cin >> pat[i];

	cin >> m;
	rep(i,1,m)
	{
		int k, flag=1, a;
		cin >> k;
		while (k--)
		{
			cin >> a;
			rep(j,1,n)
			{
				if (a == pat[j])
					flag = 0;
			}
		}
		ans += flag;
	}
	cout << ans << endl;
}

