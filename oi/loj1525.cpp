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
const int INF=0x7f7f7f7f, N = 2e4+10, M = 1e5+10;

int p[N<<1], a[M], b[M], w[M], id[M], n, m;

inline int find (int x)
{
	return (x==p[x]? x : p[x]=find(p[x]));
}
inline void U (int x, int y)
{
	p[find(x)] = find(y);
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> a[i] >> b[i] >> w[i], id[i]=i;
	for (int i=1; i<=n*2; i++) p[i] = i;
	sort(id,id+m, [](int x, int y){return w[x]>w[y];});
	for (int i=0; i<m; i++)
	{
		int aa=find(a[id[i]]), bb=find(b[id[i]]);
		int ar=find(a[id[i]]+n), br=find(b[id[i]]+n);
		if (aa==bb)
		{
			cout << w[id[i]] << '\n';
			return 0;
		}
		U(aa,br), U(bb,ar);
	}
	cout << 0 << '\n';
}
