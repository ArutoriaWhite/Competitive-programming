#include<iostream>
#include<string.h>
using namespace std;
#define DE cout << " ::"
const int maxN = 2010, maxK=1e5+10, LOG=11;

int w[maxN], l[maxN], r[maxN], p[maxN][LOG+3];

// jump
inline void par (int u, int px)
{
	p[u][0] = px;
	for (int i=1; i<LOG; i++)
	{
		if (p[ p[u][i-1] ][i-1]<0)
			break;
		p[u][i] = p[ p[u][i-1] ][i-1];
	}
}
inline int jump (int u, int wx)
{
	int s=LOG;
	while (s>0)
	{
		DE << p[u][s] << ' ';
		DE << "u " << u << " s " << s << '\n';
		if (p[u][s]<0 || w[ p[u][s] ]>wx)
		{
			s--;
		}
		else
		{
			u = p[u][s];
		}
	}
}

void dfs (int u)
{
	if (u==0) return;
	DE << "dfs " << w[u] << '\n';
	dfs(l[u]), dfs(r[u]);
}

int main()
{
	// init
	memset(p,-1,sizeof(-1));
	w[0] = 1e9;
	int x, cnt=0, u=0;
	while (cin >> x)
	{
		DE << cnt << '\n';
		if (x<w[u])
		{
			l[u] = ++cnt;
			w[l[u]] = x;
			par (l[u],u);
			u = l[u];
		}
		else
		{
			u = jump( u, x);
			r[u] = ++cnt;
			w[r[u]] = x;
			par (r[u],u);
			u = r[u];
		}
	}
	dfs(1);
}
