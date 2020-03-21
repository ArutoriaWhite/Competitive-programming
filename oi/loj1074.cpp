#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 9;

int ans[N+5][N+5], blo[5][5], ver[N+5], hor[N+5], w[N+5][N+5], res = -1, ordy[N], blank[N];

inline bool cmp (int a, int b)
{
	return blank[a]<blank[b];
}
inline void init()
{
	for (int u=0,d=N,l=0,r=N,cnt=6; d-u>0; u++,d--,l++,r--,cnt++)
	{
		for (int y=u; y<d; y++)
			for (int x=l; x<r; x++)
				w[x][y] = cnt;
	}
	for (int i=0; i<N; i++) ordy[i] = i;
}
inline bool can (int x, int y, int k)
{
	return !( blo[x/3][y/3]&(1<<k) || ver[x]&(1<<k) || hor[y]&(1<<k) );
}
inline void add (int x, int y, int k)
{
	blo[x/3][y/3] |= (1<<k);
	ver[x] |= (1<<k);
	hor[y] |= (1<<k);
}
inline void remove (int x, int y, int k)
{
	blo[x/3][y/3] &= (~(1<<k));
	ver[x] &= (~(1<<k));
	hor[y] &= (~(1<<k));
}
void dfs (int s, int d)
{
	if (d==N*N)
	{
		res = max(s, res);
		return;
	}
	int x = d%N, y = ordy[d/N];
	if (ans[x][y]!=0) 
	{
		dfs(s+ans[x][y]*w[x][y],d+1);
		return;
	}
	for (int i=1; i<=N; i++)
	{
		if (can(x,y,i))
		{
			add(x,y,i);
			dfs(s+i*w[x][y],d+1);
			remove(x,y,i);
		}
	}
}

int main()
{
	akiyama;
	init();
	for (int y=0; y<N; y++)
		for (int x=0; x<N; x++)
			cin >> ans[x][y], add(x,y,ans[x][y]);
	for (int y=0; y<N; y++)
		for (int x=0; x<N; x++)
			if (ans[x][y] == 0) blank[y]++;
	sort(ordy,ordy+N,cmp);
	dfs(0,0);
	cout << res << '\n';
}
