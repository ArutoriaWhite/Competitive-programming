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
#define low(x) (x&(-x))
using namespace std;
typedef pair<int,int> pii;

const int N = 5e5+10;

int tr[N], n, m;

inline int query (int i)
{
	int sum = 0;
	for(; i>0; i-=low(i)) sum += tr[i];
	return sum;
}
inline void add (int i, int x)
{
	for (; i<=n; i+=low(i))
		tr[i] += x;
}

signed main()
{
	pui
	cin >> n >> m;
	rep(i,1,n)
	{
		int a; cin >> a;
		add(i,a);
	}
	while (m--)
	{
		int o, x, y;
		cin >> o >> x >> y;
		if (o == 1) add(x,y);
		else cout << query(y) - query(x-1) << endl;
	}
}
