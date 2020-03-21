#include<iostream>
using namespace std;
#define maxN (100000+10)

int to[maxN], from[maxN];
inline void init( int n)
{
	for (int i=0; i<n; i++)
		to[i] = i+1;
	to[n] = 0;
	
	for (int i=1; i<=n; i++)
		from[i] = i-1;
	from[0] = -1;
}
inline void rm( int x)
{
	to[ from[x] ] = to[x];
	from[to[x]] = from[x];
}
inline void swap( int x)
{
	int a = from[from[x]], b = from[x],
		c = x, d = to[x];
	to[a] = c;
	to[b] = d, from[b] = c;
	to[c] = b, from[c] = a;
	from[d] = b;	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	init(n);
	
	for (int i=0; i<m; i++)
	{
		int opr, x;
		cin >> opr >> x;
		if (opr==0)
			rm(x);
		else if (opr==1 && to[0]!=x)
			swap(x);
	}
	for (int i=to[0]; i!=0; i=to[i])
	{
		cout << i;
		if (to[i]==0) cout << '\n';
		else cout << ' ';
	}
}
