#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

int n, m;
vector<int> adj[N], to, id, st;
int eid, bccid, dfst;
int l[N], d[N];
int vis[N], out[N];
int bcc[N];

void add (int u, int v, int _eid)
{
	adj[u].push_back(to.size());
	to.push_back(v);
	id.push_back(_eid);
}

void dfs (int u, int last_eid)
{
//	de(u), de(adj[u].size()), dd;
	d[u] = l[u] = ++dfst;
	st.push_back(u);
	for (auto i: adj[u])
	{
//		de(i), de(to[i]), dd;
		if (id[i] == last_eid) continue;
		if (!d[to[i]])
		{
			dfs(to[i],id[i]);
			l[u] = min(l[u], l[to[i]]);
		}
		else l[u] = min(l[u], d[to[i]]);
	}
	if (l[u] == d[u])
	{
		bccid++;
		int x;
		do
		{
			x = st.back(); st.pop_back();
			bcc[x] = bccid;
		}while(x!= u);
	}
}
void dfs2 (int u)
{
	vis[u] = 1;
	for (auto i: adj[u])
	{
		int v = to[i];
		if (vis[v]) continue;
		if (bcc[v] != bcc[u])
			out[bcc[u]]++;
		dfs2(v);
	}
}

int main()
{
	Eriri
	cin >> n >> m;
	for (int i=0,a,b; i<m; i++)
	{
		cin >> a >> b;
		++eid;
		add(a,b,eid);
		add(b,a,eid);
	}
	dfs(1,-1);
//	for (int i=1; i<=n; i++)
//		de(i), de(bcc[i]), de(d[i]), de(l[i]), dd;
	dfs2(1);
//	for (int i=1; i<=bccid; i++)
//		de(i), de(out[i]), dd;

	if (bccid == 1) cout << 0 << '\n';
	else if (bccid == 2) cout << 1 << '\n';
	else
	{
		int res = 0;
		for (int i=1; i<=bccid; i++)
			if (i != bcc[1])
                res += out[i]==0;
			else
				res += out[i]==1; 
		cout << (res+1)/2 << '\n';
	}
}