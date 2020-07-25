#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define getd(u) (d[u.w[1]][u.w[2]][u.w[3]][u.w[4]][u.w[5]])
using namespace std;
typedef pair<int,int> Pii;

int n, res, t;
int d[55][55][55][55][55], v[6];
struct Cups {int w[6];};
queue<Cups> q;

inline bool suc (Cups c)
{
	for (int i=1; i<=n; i++)
		if (c.w[i] == t)
			return 1;
	return 0;
}
inline Cups clear (Cups c, int k)
{
	c.w[k] = 0;
	return c;
}
inline Cups fill (Cups c, int k)
{
	c.w[k] = v[k];
	return c;
}
inline Cups move (Cups c, int j, int k)
{
	if (c.w[j] <= v[k] - c.w[k])
		c.w[k] += c.w[j], c.w[j] = 0;
	else
	{
		c.w[j] -= v[k] - c.w[k];
		c.w[k] = v[k];
	}
	return c;
}

int bfs ()
{
	q.push({{0,0,0,0,0,0}});
	d[0][0][0][0][0] = 1;
	while (!q.empty())
	{
		Cups u = q.front();
		q.pop();
		if (suc(u))
			return getd(u)-1;
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				if (i == j)
				{
					Cups v = clear(u,i);
					if (!getd(v))
						getd(v) = getd(u)+1, q.push(v);
					v = fill(u,m i);
					if (!getd(v))
						getd(v) = getd(u)+1, q.push(v);					
				}
				else
				{
					Cups v = move(u,i,j);
					if (!getd(v))
						getd(v) = getd(u) + 1, q.push(v);
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> v[i];
	cin >> t;
	cout << bfs() << '\n';
}