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

int n, k, p, x, y, sum;
int ycnt, scnt, lcnt;
int fill1, filly;

signed main()
{
	cin >> n >> k >> p >> x >> y;
	rep(i,1,k)
	{
		int a; cin >> a;
		if (a == y) ycnt++;
		else if (a > y) lcnt++;
		else scnt++;
		sum += a;
	}
	
	int h = n/2+1;	
	if (scnt >= h)
	{
		cout << -1 << endl;
		return 0;
	}

	if (lcnt+ycnt >= h)
	{
		fill1 = n - k;
	}
	else
	{
		filly = h - lcnt - ycnt;
		fill1 = h - scnt - 1;
	}

	if (sum + fill1*1 + filly*y > x)
	{
		cout << -1 << endl;
		return 0;
	}	
	
	rep(i,1,fill1) cout << 1 << ' ';
	rep(i,1,filly) cout << y << ' ';
}
