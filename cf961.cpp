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

typedef pii V;
V operator - (V i, V j){ return {i.ff-j.ff, i.ss-j.ss}; };
int operator ^ (V i, V j){ return i.ff*j.ss - i.ss*j.ff; };

const int N = 1e5+10;

int n;
V a[N];

int coline (V p, V q, V r){ return ((q-p)^(r-p))==0; }
int check (V p1, V p2, V p3)
{
	if (coline(p1,p2,p3))
	{
		vector<pii> others;
		rep(i,1,n)
		{
			if (a[i]==p1||a[i]==p2||a[i]==p3)
				continue;
			if (coline(p1,p2,a[i]))
				continue;
			else
				others.pb(a[i]);
		}
		if (others.size() <= 2) return 1;
		for (int i=2; i<others.size(); i++)
			if (!coline(others[0],others[1],others[i]))
				return 0;
		return 1;
	}
	V p4 = {9e18,9e18};
	rep(i,1,n)
	{
		if (a[i] == p1 || a[i]==p2 || a[i]==p3)
			continue;
		else if (coline(p1,p2,a[i]))
			continue;
		else if (p4 == V{9e18,9e18})
			p4 = a[i];
		else if (coline(p3,p4,a[i]))
			continue;
		else
		{
			return 0;
		}
	}
	return 1;
}
signed main()
{
	cin >> n;
	rep(i,1,n) cin >> a[i].ff >> a[i].ss;
	if (n <= 4)
	{
		cout << "YES" << endl;
		return 0;
	}
	
	if (check(a[1],a[2],a[3]) || check(a[1],a[3],a[2]) || check(a[2],a[3],a[1]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
