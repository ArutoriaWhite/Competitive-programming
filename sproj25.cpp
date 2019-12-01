#include<iostream>
using namespace std;

int const maxN=1e2+10, maxI=1e6+10;

int n, m;
int f[maxN], r[maxN], to[maxI];

inline void push (int i, int x)
{
	if (f[i]==0) f[i] = x;
	else to[r[i]] = x;
	r[i] = x;
	to[x] = 0;	
}
inline void pop (int i)
{
	if (f[i]==0)
	{
		cout << "queue " << i << " is empty!\n";
		return;
	}
	int h = f[i];
	f[i] = to[h];
	to[h] = 0;
}
inline void move (int i, int j)
{
	if (f[j]==0)
	{
		f[j]=f[i];
		r[j]=r[i];
	}
	else
	{
		to[r[j]] = f[i];
		r[j] = r[i];
	}
	f[i] = r[i] = 0;
}
inline void print()
{
	for (int i=1; i<=n; i++)
	{
		cout << "queue " << i << ": ";
		if (f[i]==0)
		{
			cout << "empty\n";
			continue;
		}
		for (int j=f[i]; j!=to[r[i]]; j=to[j])
		{
			cout << j;
			if (to[j]==to[r[i]]) cout << '\n';
			else cout << ' ';
		}
	}	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int t=0; t<m; t++)
	{
		string opr;
		int i, j;
		cin >> opr;
		if (opr=="ADD")
		{
			cin >> i >> j;
			push(i,j);
		}
		else if (opr=="LEAVE")
		{
			cin >> i;
			pop(i);
		}
		else
		{
			cin >> i >> j;
			move(i,j);
		}
	}
	print();
}
