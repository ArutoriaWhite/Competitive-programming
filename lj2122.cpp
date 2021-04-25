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

int n, m;
struct ST
{
	int sq[N<<1], sum[N<<1], len[N<<1], tag[N<<1];

	// make whole parent of p replace their lazy operation to son
	void push (int p) 
	{
		for (int h=__lg(p); h>0; h--)
		{
			int x = p>>h;
			if (!tag[x]) continue;
			upd(x<<1, tag[x]);
			upd(x<<1|1,tag[x]);
			tag[x] = 0;
		}
	}
	// before use must determine that fathers tag has been cleard
	// update modified nodes's parent
	void pull (int p)
	{
		while (p>1)
		{
			sq[p>>1] = sq[p]+sq[p^1];
			sum[p>>1] = sum[p]+sum[p^1];
			p>>=1;
		}
	}
	// apply one tag on a node
	void upd (int p, int x)
	{
		tag[p] += x;
		sq[p] += 2*x*sum[p];
		sq[p] += x*x*len[p];
		sum[p] += len[p]*x;
	}
	void build ()
	{
		for (int i=0; i<n; i++)
		{
			cin >> sum[i+n];
			sq[i+n] = sum[i+n]*sum[i+n];
			len[i+n] = 1;
		}
		for (int i=n-1; i>0; i--)
		{
			len[i] = len[i<<1] + len[i<<1|1];
			sq[i] = sq[i<<1] + sq[i<<1|1];
			sum[i] = sum[i<<1] + sum[i<<1|1];
		}
	}
	void modify (int l, int r, int x)
	{
		l+=n, r+=n;
		push(l), push(r);
		for (int tl=l,tr=r; tl<tr; tl>>=1,tr>>=1)
		{
			if (tl&1) upd(tl++,x);
			if (tr&1) upd(--tr,x);
		}
		push(l), push(r);
		pull(l), pull(r);
	}
	int query (int *tree, int l, int r)
	{
		int res=0;
		l+=n, r+=n;
		push(l), push(r);
		for (int tl=l,tr=r; tl<tr; tl>>=1,tr>>=1)
		{
			if (tl&1) res += tree[tl++];
			if (tr&1) res += tree[--tr];
		}
		return res;
	}
} st;

pii beauti (int x, int y)
{
	return {x/__gcd(x,y), y/__gcd(x,y)};
}
signed main()
{
	ShinraTensei
	cin >> n >> m;
	st.build();
	while (m--)
	{
		int o, l, r, x, k;
		cin >> o >> l >> r;
		l--;
		k = r-l;
		if (o==1)
		{
			cin >> x;
			st.modify(l,r,x);
		}
		else if (o==2)
		{
			int sum = st.query(st.sum, l, r);
			pii res = beauti(sum, k);
			cout << res.ff << '/' << res.ss << '\n';
		}
		else 
		{
			int sqsum = st.query(st.sq, l, r);
			int sum = st.query(st.sum, l, r);
			pii res = beauti(k*sqsum - sum*sum, k*k);
			cout << res.ff << '/' << res.ss << '\n';
		}
	}
}
