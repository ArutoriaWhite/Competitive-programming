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

signed main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a[4];
		rep(i,1,3) cin >> a[i];
		sort(a+1,a+4);
		if (a[1]+a[2] < a[3]) cout << "illegal triangle\n";
		else
		{
			a[1]*=a[1], a[2]*=a[2], a[3]*=a[3];
			if (a[1]+a[2] == a[3]) cout << "right triangle\n";
			else if (a[1]+a[2] < a[3]) cout << "acute triangle\n";
			else cout << "obtuse triangle\n";
		}
	}
}
