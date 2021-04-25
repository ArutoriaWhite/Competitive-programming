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

const int N = 1e6+10;

int tr[N], n, m;

int low (int i){ return i&-i; }
void modify (int i, int x)
{
	for (; i<=n; i+=low(i))
		tr[i] += x;
}
int query (int i)
{
	int ans = 0;
	for (; i>0; i-=low(i))
		ans += tr[i];
	return ans;
}	

signed main()
{
	cin >> n >> m;
	while (m--)
	{
		int o, x, y;
		cin >> o >> x;
		if (o == 1 && cin >> y) modify(x,y);
		else cout << query(x) << endl;
	}
}
