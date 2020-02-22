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
const int INF=0x7f7f7f7f, N = 1e5+10;

int G[2][N], n, q, cnt;

inline void upd (int x, int y)
{
	int mult = (G[x][y]==1? -1 : 1), ano = !x;
	for (int i=y-1; i<=y+1; i++)
		if (0<=y&&y<n)
			cnt += G[ano][i]*mult;
	G[x][y] = !G[x][y];
}

inline void printG ()
{
	for (int y=0; y<n; y++)
		for (int x=0; x<2; x++)
			cout << G[x][y] << "\n "[x+1<2];
	de(cnt), dend;
}

int main()
{
	akiyama;
	cin >> n >> q;
	for (int i=0,x,y; i<q; i++)
	{
		cin >> x >> y;
		upd(x-1,y-1);
		cout << (cnt==0? "Yes\n" : "No\n");
	}
}
