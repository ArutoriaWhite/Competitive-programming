#include<iostream>
#include<algorithm>
using namespace std;
const int maxN = 1e5+10;

int l[maxN], r[maxN], val[maxN], cnt;
bool exi[maxN];

inline void init()
{
	cnt = 0;
}
inline void print (int u)
{
	if (u==0) return;
	print(l[u]);
	cout << val[u] << ' ';
	print(r[u]);
}
inline int ins (int u, int x)
{
	if ( u==0 )
	{
		val[++cnt] = x;
		return cnt;
	}
	if (x<val[u])
		l[u] = ins(l[u],x);
	else if (x>val[u])
		r[u] = ins(r[u],x);
	return u;
}

inline int search (int u)
{
	if (r[u] == 0) return u;
	return search(r[u]);
}

inline int del (int u, int x)
{
	if (val[u] == x)
	{
		if (l[u]==0 && r[u]>0)
			return r[u];
		if (r[u]==0 && l[u]>0)
			return l[u];
		r[ search(l[u]) ] = r[u];
		return l[u];
	}
	if (x < val[u])
		l[u] = del(l[u],x);
	else if (x > val[u])
		r[u] = del(r[u],x);
	return u;
}

int nod[3], rear, mindis;
inline void que_init()
{
	rear = 0;
	mindis = -1;
}
inline void que (int u, int q)
{
	if (u==0) return;
	int d = abs(val[u]-q);
	if (mindis<0 || d<mindis)
	{
		rear=0;
		nod[rear++] = val[u];
		mindis = d;
	}
	else if (d==mindis)
	{
		nod[rear++] = val[u];
	}
	if (q<val[u]) que(l[u],q);
	else if (q>val[u]) que(r[u],q);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();

	string opr;
	int n, x, rt=0;
	cin >> n;

	while (n--)
	{
		cin >> opr >> x;
		if (opr == "insert")
			rt = ins(rt,x);
		else if (opr == "delete")
			rt = del(rt,x);
		else
		{
			que_init();
			que(rt,x);
			sort(nod,nod+rear);
			for (int i=0; i<rear; i++)
				cout << nod[i] << ((i+1<rear)? (' '):('\n'));
		}
	}
}
