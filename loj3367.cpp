#include <iostream>
using namespace std;
const int N = 1e4+10;

int p[N], n, m;

int find (int x)
{
	if (p[x]==x) return x;
	return p[x] = find(p[x]);
}
inline void uni (int a, int b)
{
	p[find(a)] = find(b);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i=0; i<N; i++) p[i] = i;
	cin >> n >> m;
	for (int i=0,o,x,y; i<m; i++)
	{
		cin >> o >> x >> y;
		if (o==1) uni(x,y);
		else cout << (find(x)==find(y)? "Y":"N") << "\n";
	}
}
