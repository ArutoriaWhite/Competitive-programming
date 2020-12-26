#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

int a[N];

signed main()
{
	XinAi
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		rep(i,1,n) cin >> a[i];
		int cnt=0;
		rep(i,1,n) cnt += a[i]==0;
		if (cnt >= n/2)
		{
			cout << n/2 << '\n';
			rep(i,1,n/2)
			{
				cout << 0 << ' ';
			}
			cout << '\n';
		}
		else
		{
			int k = n/2;
			if ((n/2)&1) k++;
			cout << k << '\n';
			rep(i,1,k) cout << 1 << ' ';
			cout << '\n';
		}
	}
}
