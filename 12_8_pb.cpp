#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxN=1e5+10, maxM=3*(1e5)+10;

int n, m;
struct edge { int a, b, w; };
edge sagiri[maxM];

// disj
int p[maxN];
inline void init()
{
	for (int i=0; i<maxN; i++)
		p[i] = i;
}
int find (int x)
{
	if (p[x] == x)
		return x;
	p[x] = find(p[x]);
	return p[x];
}
int uni (int x, int y)
{
	p[ find(x) ] = find(y);
}

// kruskal
inline bool cmp (const edge &a, const edge &b)
{
	return a.w > b.w;
}
int krusk()
{
	init();
	sort (sagiri,sagiri+m,cmp);
	int res = 0;
	for (int i=0; i<m; i++)
	{
		edge u = sagiri[i];
		if (find(u.a) == find(u.b)) continue;
		uni(u.a,u.b);
		res += u.w;
	}
	return res;
}

int main()
{
	cin >> n >> m;
	int sum=0;
	for (int i=0; i<m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		sagiri[i] = { a, b, w};
		sum += w;
	}

	cout << sum-krusk() << '\n';
	
}
