#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back()
#define pui ios::sync_with_stdio(), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

int n, m, k, p;

signed main()
{
	cin >> n >> m >> k >> p;
	if (n == p)
	{
		if (k % n == 0)
		{
			cout << "YES\n";
			rep(i,1,n)
			{
				cout << k/n << ' ' << m-k/n << '\n';
			}
		}
		else
		{
			cout << "NO\n";
		}
		return 0;
	}
	int mxcnt = min(m,k/p);
	int sumAB = k - mxcnt*p;
	int Asize = sumAB%(n-p);
	int Bsize = (n-p) - Asize;
	int Acnt = sumAB/(n-p)+1;
	int Bcnt = sumAB/(n-p);

	if (mxcnt > (Asize==0? Bcnt:Acnt))
	{
		cout << "YES\n";
		rep(i,1,p) cout << mxcnt << ' ' << m - mxcnt << '\n';
		rep(i,1,Asize) cout << Acnt << ' ' << m - Acnt << '\n';
		rep(i,1,Bsize) cout << Bcnt << ' ' << m - Bcnt << '\n';
	}
	else
	{
		cout << "NO\n";
	}
}
