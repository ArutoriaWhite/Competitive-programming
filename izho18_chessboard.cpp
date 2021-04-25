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

const int N = 1010;
map<pii,int> dp[N];
set<pii> bl;
int n, k, md[N];

int sol (int r, int c, int z) // left, top is r, c, size z
{
	if (z == 1)
		dp[z][pii(r,c)] = bl.find({r,c})!=bl.end();
	else
	{
		int nz = z/md[z];
		for (int i=r; i<r+z; i+=nz)
			for (int j=c; j<c+z; j+=nz)
				dp[z][pii(r,c)] += dp[nz][pii(i,j)];
	}
	return dp[z][pii(r,c)];
}
void sieve()
{
	for (int i=2; i<N; i++)
	{
		if (!md[i]) md[i] = i;
		for (int j=i*i; j<N; j+=i)
			if (!md[j])
				md[j] = i;
	}
}

signed main()
{
	sieve();
	cin >> n >> k;
	while (k--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		bl.insert({x1,y1});
	}
	int ans = 9e18;
	for (int z=1; z<n; z++)
	{
		if (n%z) continue;
		// count b1 total
		// count b2 total
		// count b1 big cnt
		// count b2 big cnt
		// upd ans
		// block base on 1
		int t1=0, t2=0;
		for (int r=1; r<=n; r+=2*z)
			for (int c=1; c<=n; c+=2*z)
				t1 += sol(r,c,z);
		for (int r=z+1; r<=n; r+=2*z)
			for (int c=z+1; c<=n; c+=2*z)
				t2 += sol(r,c,z);
		int c1=0, c2=0;		
		c1 = (n/z)*(n/z)/2+((n/z)&1), c2 = (n/z)*(n/z)/2;
		de(z), de(c1), de(c2), de(t1), de(t2), dd;
		ans = min(ans, c1*z*z-t1+t2);
		ans = min(ans, t1+c2*z*z-t2);
	}
	cout << ans << endl;
}
