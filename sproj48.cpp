#include<iostream>
<<<<<<< HEAD
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
=======
#include<memory.h>
using namespace std;
#define DE cout << " ::"
const int maxN = 2000+10, LOG = 12;

int l[maxN], r[maxN], w[maxN], p[maxN][LOG+3];

inline void init()
{
	memset(p,-1,sizeof(p));
	w[0] = 0x3f3f3f3f;
}

inline int setPar (int x, int px)
{
	DE << "setP ";
	DE << x << ' ' << px << '\n';
	p[x][0] = px;
	for (int i=1; i<LOG; i++)
		p[x][i] = p[p[x][i-1]][i-1];
	for (int i=0; i<LOG; i++)
		cout << w[p[x][i]] << ' ' ; 
	cout << '\n';
}

inline int jump (int x, int wx)
>>>>>>> ab66ddf82af78c15c913a5d769378f786df31809
{
	int s=LOG;
	while (s>0)
	{
<<<<<<< HEAD
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
=======
		if (p[x][s]<0 || w[p[x][s]]<wx)
			s--;
		else
			x = p[x][s];
	}
	DE << "jump " << x << '\n';
	return x;
>>>>>>> ab66ddf82af78c15c913a5d769378f786df31809
}

void dfs (int u)
{
<<<<<<< HEAD
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
=======
	if (u!=0)
		cout << w[u] << '\n';
	if (l[u]!=0)
		dfs(l[u]);
	if (r[u]!=0)
		dfs(r[u]);

}

int main() {
	init();
	
	int wx, u=0, cnt=0;
	while (cin >> wx)
	{
		if (wx<w[u])
		{
			l[u] = ++cnt;
			setPar(cnt,u);
			w[cnt] = wx;
			u = cnt;
		}
		else
		{
			u = jump(u,wx);
			r[u] = ++cnt;
			setPar(cnt,u);
			w[cnt] = wx;
			u = cnt;
		}
	}
	dfs(0);
	return 0;
>>>>>>> ab66ddf82af78c15c913a5d769378f786df31809
}
