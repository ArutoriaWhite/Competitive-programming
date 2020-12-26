#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6+10;

int gre[N], les[N], n, k, ans1[N], ans2[N];
struct Q
{
	pii a[N];
	int f, r;
	int sz(){ return r-f;};
} gt, ls;

signed main()
{
	XinAi
	cin >> n >> k;
	int j=0;
	for (int i=0,x; i<n; i++)
	{
		cin >> x;
		while (gt.sz()>0 && gt.a[gt.r-1].S>=x) gt.r--;
		gt.a[gt.r++] = {i,x};
		while (ls.sz()>0 && ls.a[ls.r-1].S<=x) ls.r--;
		ls.a[ls.r++] = {i,x};
		while (gt.sz()>0 && gt.a[gt.f].F<=i-k) gt.f++;
		while (ls.sz()>0 && ls.a[ls.f].F<=i-k) ls.f++;
		if (i+1 >= k)
		{
			ans1[j]=gt.a[gt.f].S;
			ans2[j]=ls.a[ls.f].S;
			j++;
		}
	}
	for (int i=0; i<j; i++) cout << ans1[i] << ' ';
	cout << '\n';
	for (int i=0; i<j; i++) cout << ans2[i] << ' ';
	cout << '\n';
}

