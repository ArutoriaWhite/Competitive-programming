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

const int N = 1e5+10;

typedef pair<double,double> V;
double operator * (V i, V j){ return i.ff*j.ff+i.ss*j.ss; }
double operator ^ (V i, V j){ return i.ff*j.ss - i.ss*j.ff; }
V operator - (V i, V j){ return {j.ff-i.ff,j.ss-i.ss}; }

int n;
V v[N], st[N];

inline double convexhull ()
{
	sort(v+1,v+1+n);
	double ans = 0;
	int r=0;

	for (int i=1; i<=n; i++)
	{
		while (r>1 && ((st[r-2]-st[r-1])^(st[r-2]-v[i]))<=0) r--;
		st[r++] = v[i];
	}
	for (int i=0; i+1<r; i++) ans += sqrt((st[i]-st[i+1])*(st[i]-st[i+1]));

	r = 0;
	for (int i=n; i>0; i--)
	{
		while (r>1 && ((st[r-2]-st[r-1])^(st[r-2]-v[i]))<=0) r--;
		st[r++] = v[i];
	}
	for (int i=0; i+1<r; i++) ans += sqrt((st[i]-st[i+1])*(st[i]-st[i+1]));
	
	return ans; 
}

signed main()
{
	pui
	cin >> n;
	rep(i,1,n) cin >> v[i].ff >> v[i].ss;
	cout << fixed << setprecision(2) << convexhull() << endl;
}
