#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 5e4+10;

int a[N], n, q;

signed main()
{
	ShinraTensei
	cin >> n >> q;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) a[i] += a[i-1];
	while (q--)
	{
		int x;
		cin >> x;
		cout << upper_bound(a+1,a+1+n,x)-a << '\n';
	}
}
