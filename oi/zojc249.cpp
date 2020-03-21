#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb emplace_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = (1<<10)+10;

int word[N][N], mord[N][N], hus[N], n, T, wif[N];
queue<int> q;

inline void init()
{
	mem(word,0);
	mem(mord,0);
	mem(hus,0);
	while (!q.empty())
		q.pop();
}
inline bool marry (int x, int j)
{	
	if (hus[j]==0 || mord[x] < mord[hus[j]])
	{
		q.push(hus[j]);	
		hus[j] = x;
		wif[x] = j;
		return 1;
	}
	return 0;
}
inline bool ask (int x)
{
	for (int i=1; i<=n; i++)
		if (marry(x,word[x][i]))
			return 1;
	return 0;
}
int main()
{
	akiyama;
	cin >> T;
	while (T--)
	{
		init();
		cin >> n;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				cin >> word[i][j];
		for (int i=1; i<=n; i++)
			for (int j=1,x; j<=n; j++)
				cin >> x, mord[i][x] = j;
		for (int i=1; i<=n; i++) q.push(i);
		while (!q.empty())
		{
			int x = q.front(); q.pop();
			if (!ask(x)) q.push(x);
		}
		for (int i=1; i<=n; i++)
			cout << i << ' ' << wif[i] << '\n';

	}
}
