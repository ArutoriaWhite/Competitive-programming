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
const int N = 2e5+10;

int n, m;
int pre[N<<1];

int bs (int op, int x)
{
	return lower_bound( pre+1, pre+2*n+1, pre[op]+x ) - pre;
}

signed main()
{
	ShinraTensei
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> pre[i+1], pre[i+n+1] = pre[i+1];

	for (int i=1; i<=n*2; i++)
		pre[i] = pre[i]+pre[i-1];

	int op=0, q;
	for (int i=0; i<m; i++)
	{
		cin >> q;
		op = bs(op,q)%n;
	}
	
	cout << op << '\n';
}
