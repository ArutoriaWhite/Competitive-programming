#include <iostream>
#include <set>
#include <tuple>
#define AT(t,i) get<i>(t)
using namespace std;
typedef tuple<int,int,int,int,int> cups;
const int M = 1e6, N = 5;


int f, r, n, t, lim[N], dep[M];
cups q[M], rt;
set< cups > vis;

inline cups clear (cups c, int k)
{
	AT(c,k) = 0;
	return c;
}
inline cups fill (cups c, int k)
{
	AT(c,k) = lim[k];
	return c;
}
inline cups move (cups c, int fr, int to)
{
	int x = min(AT(c,fr),lim-AT(c,to));
	AT(c,fr) -=x, AT(c,to) += x;
	return c;
}
inline void push (const &c, int d)
{
	if (vis.find(c)==vis.end())
		dep[r] = d, q[r++] = c;
}
inline int bfs()
{
	dep[r] =0, cups[r++] = rt;
	while (f<r)
	{
		int d = dep[f];
		cups &u = q[f++];
		// check res
		for (int i=0; i<n; i++)
			if (AT(cups,i)==t)
					return d;
		// gen
		for (int i=0; i<n; i++)
			push(fill(u,i),d+1);
		for (int i=0; i<n; i++)
		{
		}
		
	}
	return -1;
}

int main ()
{
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> lim[i], AT(rt,i)=0;
	cout << bfs() << '\n';
}
