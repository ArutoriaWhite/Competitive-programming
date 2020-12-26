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
const int N = 1e4+10;

int a[N], n, owo[N], ans[N];

int md (int i, int j)
{
	int res;
	cout << "? " << i << ' ' << j << '\n';
	cin >> res;
	return res;
}
int cmp (int a, int b)
{
	return md(b,a) < md(a,b);
}

signed main()
{
	cin >> n;
	int mx=1;
	rep(i,2,n)
	{
		int x=md(mx,i);
		int y=md(i,mx);
		if (x>y)
		{
			ans[mx] = x;
			mx = i;
		}
		else
		{
			ans[i] = y;
		}
	}
	ans[mx] = n;
	cout << "! ";
	rep(i,1,n) cout << ans[i] << ' ';
	cout << '\n';
}
