#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 3e5+10, M = 40;
typedef bitset<32> bs;

int l[N<<3], r[N<<3], cnt=1;
int n, m;
char _;

bs read()
{
	int sum=0, x;
	rep(i,0,3)
	{
		if (i>0) cin >> _;
		cin >> x;
		sum = (sum<<8)+x;
	}
	bs res(sum);
	return res;

}
void walk (bs x, int lim)
{
	int u = 1;
	for (int i=31,j=0; i>=0; i--,j++)
	{
		if (j>=lim) break;
		if (x[i]==0)
			u = l[u] = (l[u]? l[u]:++cnt);
		else
			u = r[u] = (r[u]? r[u]:++cnt);
		if (u<0) return;
	}
	l[u] = r[u] = -1;
}
int ask (bs x)
{
	int u = 1;
	for (int i=31; i>=0; i--)
	{
		u = (x[i]? r[u]:l[u]);
		if (u<0) return 1;
		if (u==0) return 0;
	}
	return 1;
}

signed main()
{
	ShinraTensei
	cin >> n >> m;
	rep(i,1,n)
	{
		bs x = read();
		int lim;
		cin >> _ >> lim;
		walk(x,lim);
	}
	rep(i,1,m)
	{
		bs q = read();
		cout << (ask(q)? "TRUE":"FALSE") << '\n';
	}
}
