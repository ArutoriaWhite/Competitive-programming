#include<iostream>
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
{
	int s=LOG;
	while (s>0)
	{
		if (p[x][s]<0 || w[p[x][s]]<wx)
			s--;
		else
			x = p[x][s];
	}
	DE << "jump " << x << '\n';
	return x;
}

void dfs (int u)
{
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
}
