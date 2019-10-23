#include<iostream>
using namespace std;
#define maxN 30

int al[maxN], pos[maxN];
int stk[maxN][maxN], r[maxN];
int n;

inline void pb( int x, int b)
{
	stk[b][r[b]]=x;
	al[x]=b, pos[x]=r[b];
	r[b]++;
}

inline void clear( int a, int l)
{
	for( int i=r[a]-1; i>=l; i--)
	{
		if (stk[a][i]==a) continue;
		pb( stk[a][i], stk[a][i]);
		r[a]--;
	}
}

inline void mvOnto( int a, int b)
{
	clear(al[a],pos[a+1]);
	clear(al[b],pos[b+1]);
	stk[al[b]][r[al[b]++] = stk[al[a]][pos[a]];
	stk[al[a]][r[a]]--;
}
inline void init()
{
	for( int i=0; i<maxN; i++)
	{
		al[i]=i;
		pos[i]=0;
		stk[i][0]=i;
		r[i]=1;
	}
}

inline void print()
{
	for( int i=0; i<n; i++)
	{
		cout << i << ":";
		for( int j=0; j<r[i]; j++)
		{
			cout << ' ' << stk[i][j];
		}
		cout << " :" << r[i] << '\n';
	}
}
int main()
{
	while (cin>>n)
	{
		init();
		mvOnto(1,2);
		mvOnto(3,2);
		mvOnto(4,2);
		mvOnto(6,2);
		mvOnto(2,1);
		print();
	}	
}
