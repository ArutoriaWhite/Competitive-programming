#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 9;

int toi[200], G[N][N], sol[N][N], hor[N], ver[N], blo[3][3];
string ch;

inline void init()
{
	ch = "ROYGBIPLW*";
	for (int i=0; i<10; i++)
		toi[ch[i]] = i;
}
inline void add (int x, int y, int k)
{
	sol[x][y] = k;
	hor[y] |= (1<<k);
	ver[x] |= (1<<k);
	blo[x/3][y/3] |= (1<<k);
}
inline void del (int x, int y, int k)
{
	hor[y] -= (1<<k);
	ver[x] -= (1<<k);
	blo[x/3][y/3] -= (1<<k);
}
inline bool can (int x, int y, int k)
{
	return !((hor[y]|ver[x]|blo[x/3][y/3])&(1<<k));
}
inline void print_sol()
{
	int all_fir=1;
	for (int y=0; y<N; y++)
	{
		bool fir=1;
		for (int x=0; x<N; x++)
		{
			if (G[x][y]==N)
			{
				if(fir)
				{
					if (!all_fir) cout << '\n';
					fir = all_fir = 0;
				}
				cout << ch[sol[x][y]];
			}
		}
	}
}

bool dfs (int d)
{
	if (d==N*N)
	{
		print_sol();
		return 1;
	}
	int x = d%N, y=d/N;
	if (G[x][y]!=N)
		return dfs(d+1);
	for (int i=0; i<N; i++)
	{
		if (can(x,y,i))
		{
			add(x,y,i);
			if (dfs(d+1)) return 1;
			del(x,y,i);
		}
	}
	return 0;
}

int main()
{
	akiyama;
	init();
	char c;
	for (int y=0; y<N; y++)
		for (int x=0; x<N; x++)
		{
			cin >> c;
			G[x][y] = toi[c];
			if (G[x][y] < N)
				add(x,y,G[x][y]);
		}
	dfs(0);
}
