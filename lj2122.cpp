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

struct ST
{
	int sum[N<<1], sqsum[N<<1];
	int lz[N<<1];
	void build()
	{
		for (int i=0; i<n; i++)
		{
			sum[i+n] = a[i];
			sqsum[i+n] = a[i]*a[i];
		}
		for (int i=n-1; i>0; i--)
		{
			sum[i] = sum[i<<1] + sum[i<<1|1];
			sqsum[i] = sqsum[i<<1] + sqsum[i<<1|1];
		}
	}
	void add_tag (int u, int x)
	{

	}
	void push (int p) // move tag to son and clear self's tag
	{
		for (int h=__lg(p); h>=0; h--)
		{
			int i = p>>h;
			add_tag(i<<1, lz[i]);
			add_tag(i<<1|1,lz[i]);
			lz[i] = 0;
		}
	}
	void pull (int p) // when sun change, update itself's value by son
	{
		while (p>1)
		{
			sum[p>>1] = sum[p] + sum[p^1];
			qsum[p>>1] = qsum[p] + qsum[p^1];
		}
	}
	void modify (int l, int r, int x) // find max legal range node and update value, add tag
	{
		push(l+n), push(r+n);
		for (int tl=l+n,tr=r+n; tl<tr; tl>>=1,tr>>=1)
		{
			
		}
		pull(l+n), pull(r+n);
	}
	// make all node relation with range change to their true value, then answer
	void query (int l, int r, int x, int *tr)
	{
		
	}
} st;

pii beautiful (int x, int y)
{
	return {x/__gcd(x,y), y/__gcd(x,y)};
}

signed main()
{
	cin >> n >> m;
	rep(i,1,n) cin >> a[i-1];
	st.build();
	while (m--)
	{
		int o, l, r, x;
		cin >> o >> l >> r;
		l--;
		if (o==1)
		{
			cin >> x;
			st.modify(l,r,x);
		}
		if (o==2)
		{
			int rsum = st.query(l,r,st.sum);
			pii res = beautiful(rsum,r-l);
			cout << res << '\n';
		}
		if (o==3)
		{
			int rsum = st.query(l,r,st.sum);
			int rsqsum = st.query(l,r,st.sqsum);
			pii res = beautiful(rsum*(r-l) - rsqsum, (r-l)*(r-l));
		}
	}
}
