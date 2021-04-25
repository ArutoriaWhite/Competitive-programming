#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

/*
   
dfs state: 
1. bitset<9> blo[9]
2. bitset<9> row[9]
3. bitset<9> col[9]
4. i: position id, i/9 = row, i%9 = col, row/3, col/3, i/9/3*3+(i%9)/3

1. build init blo, row, col
2. dfs (0)
	if (i == 81)
		print
		exit(0)
	if (is empty)
		dfs(0~9)
	else
		dfs(i+1)
*/

bitset<9> blo[9], row[9], col[9];
int G[81], Gt[81];
string toc = "ROYGBIPLW";
int toi [200];

inline int gRow (int i){ return i/9; }
inline int gCol (int i){ return i%9; }
inline int gBlo (int i){ return i/9/3*3+(i%9)/3; }

inline int legal (int i, int x)
{
	return blo[gBlo(i)][x]==0 && row[gRow(i)][x]==0 && col[gCol(i)][x]==0;
}
inline void fill (int i, int x)
{
	blo[gBlo(i)][x] = 1;
	row[gRow(i)][x] = 1;
	col[gCol(i)][x] = 1;
	G[i] = x;
}
inline void unfill (int i, int x)
{
	blo[gBlo(i)][x] = 0;
	row[gRow(i)][x] = 0;
	col[gCol(i)][x] = 0;
	G[i] = -1;
}
void print()
{
	for (int i=0; i<81; i++)
	{
		if (Gt[i]) cout << toc[G[i]];
		if ((i+1)%9==0) cout << '\n';
	}
}

void dfs (int i=0)
{
	if (i == 81)
	{
		print();
		exit(0);
	}
	if (G[i] < 0)
	{
		for (int x=0; x<9; x++)
		{
			if (legal(i,x))
			{
				fill(i,x);
				dfs(i+1);
				unfill(i,x);
			}
		}
	}
	else dfs(i+1);
}

signed main()
{
	for (int i=0; i<9; i++) toi[toc[i]] = i;

	for (int i=0; i<81; i++)
	{
		char c; cin >> c;
		if (c != '*') fill(i,toi[c]);
		else Gt[i] = 1, G[i] = -1;
	}
	dfs(0);
}
