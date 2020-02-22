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
const int INF=0x7f7f7f7f, N = 40;

int G[N][N], fow[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}, n;

inline void dfs (int x, int y)
{
	if (G[x][y]!=0 || x<0 || x>=n || y<0 || y>=n) return;
	G[x][y] = -1;
	for (int i=0; i<4; i++)
		dfs(x+fow[i][0], y+fow[i][1]);
}

inline void print()
{
	for (int y=0; y<n; y++)
		for (int x=0; x<n; x++)
		{
			if (G[x][y]==-1) G[x][y] = 0;
			else if (G[x][y] == 0) G[x][y] = 2;
			cout << G[x][y] << "\n "[x+1<n];
		}
}

int main()
{
	cin >> n;
	for (int y=0; y<n; y++)
		for (int x=0; x<n; x++)
			cin >> G[x][y];
	for (int x=0; x<n; x++)
		dfs(x,0), dfs(x,n-1);
	for (int y=0; y<n; y++)
		dfs(0,y), dfs(n-1,y);
	print();
}
