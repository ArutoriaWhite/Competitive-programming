#include<iostream>
#include<tuple>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

typedef pair<pair<int, int>,char> edge;
const int maxL = 40, M = 1000007, maxR=1e5+10;

// data
string a, b;
int n, m;

// sol tree
vector<edge> sol[maxL][maxL];
inline void init_sol()
{
	for (auto &x: sol)
		for (auto &y: x) y.clear();
}
inline pair<int, int> mhash (int i, int j)
{
	return {i, j};
	//return ((int)pow(ddi,3)%M + (int)(j,7))%M;
}

// lcs
int dp[maxL][maxL], used[maxL][maxL], u;
int lcs (int i, int j)
{
	if (used[i][j]<u)
	{
		if (i==n || j==m)
		{
			dp[i][j] = 0;
		}
		else if (a[i] == b[j])
		{
			dp[i][j] = lcs(i+1,j+1)+1;
			sol[i][j].push_back( {mhash(i+1,j+1), a[i]} );
		}
		else
		{
			int x = lcs(i+1,j), y = lcs(i,j+1);
			if (x>=y)
			{
				dp[i][j] = x;
				sol[i][j].push_back( {mhash(i+1,j),'#'} );
			}
			if (y>=x)
			{
				dp[i][j] = y;
				sol[i][j].push_back( {mhash(i,j+1),'#'} );
			}
		}
	}
	return dp[i][j];
}

// dfs res gen
set<string> vis;
string s, res[maxR];
int r;
inline void init_dfs ()
{
	s="";
	r=0;
	vis.clear();
}
void dfs (pair<int, int> u, int d)
{
	if (d==0 && (vis.count(s)==0))
	{
		vis.insert(s);
		res[r++] = s;
		return;
	}
	for( auto v: sol[u.first][u.second])
	{
		if (v.second != '#')
		{
			s += v.second;
			dfs(v.first,d-1);
			s.pop_back();
		}
		else
		{
			dfs(v.first,d);
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (u=1; u<=T; u++)
	{
		cin >> a >> b;
		n = a.size(), m=b.size();

		init_sol();
		init_dfs();
		
		dfs(mhash(0,0),lcs(0,0));

		cout << r << '\n';
		sort( res, res+r);
		for (int i=0; i<r; i++)
		{
			cout << res[i] << '\n';
		}
	}
}
