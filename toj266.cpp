#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e4+10, M = sqrt(1e4)+10;

priority_queue<int,vector<int>,less<int>> pq[N];
int mx_pq[M], n, q, sz;

void upd (int p)
{
	int bid=p/sz, l=sz*bid, r=sz*(bid+1)-1;
	mx_pq[bid]=l;
	rep(i,l,r)
	{
		if (pq[i].empty()) continue;
		if (pq[mx_pq[bid]].empty() || pq[i].top()>=pq[mx_pq[bid]].top())
			mx_pq[bid] = i;
	}
}
void comp (int &res, int i)
{
	if (pq[i].empty()) return;
	if (res==-1 || pq[i].top() >= pq[res].top()) res=i;
}
int query (int l, int r)
{
	int L=l/sz, R=r/sz, res=-1;
	if (L==R)
	{
		rep(i,l,r) comp(res,i);
	}
	else
	{
		int rb=(L+1)*sz-1;
		int lb=(R-1)*sz+1;
		rep(i,l,rb)    comp(res,i);
		rep(i,L+1,R-1) comp(res,mx_pq[i]);
		rep(i,rb,r)    comp(res,i);
	}
	if (res==-1) return -1;
	else
	{
		int ans=pq[res].top();
		pq[res].pop();
		upd(res);
		return ans;
	}
}
signed main()
{
	XinAi
	cin >> n >> q;
	sz = sqrt(n);
	for (int i=0,t,a,b; i<q; i++)
	{
		cin >> t >> a >> b;
		if (t==0)
			pq[a].push(b), upd(a);
		else
			cout << query(a,b) << '\n';
	}
}
