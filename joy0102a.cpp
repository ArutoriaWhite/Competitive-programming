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
const int N = 1e5+10;

int a[N], b[N], cnt[2][2], n, res;

signed main()
{
	cin >> n;
	rep(i,1,n)
	{
		char c;
		cin >> c;
		a[i] = c-'0';
	}
	rep(i,1,n)
	{
		char c;
		cin >> c;
		b[i] = c-'0';
	}
	rep(i,1,n)
	{
		cnt[a[i]][b[i]]++;
	}
	rep(i,1,n)
	{
		if (b[i]) continue;
		res += cnt[!a[i]][0];
		res += cnt[!a[i]][1]*2;
	}
	cout << (res>>1) << '\n';
}
