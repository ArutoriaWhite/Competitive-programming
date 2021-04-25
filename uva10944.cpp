#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 25, LG = 17;

int dp[N][N][(1<<LG)]; //min dis walk to end
int id[N][N];
int sh[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
int n, m, opr, opc, fin, cnt;

int f (int r, int c, int k)
{
	if (dp[r][c][k] == -1)
	{
		if (k == fin) dp[r][c][k] = max(abs(r-opr),abs(c-opc));
		else
		{
			dp[r][c][k] = 1e9;
			rep(i,0,7)
			{
				int nr = sh[i][0]+r;
				int nc = sh[i][1]+c;
				if (nr<1 || nr>n || nc<1 || nc>m) continue;
				int nk = (id[nr][nc]? (k|(1<<id[nr][nc])):k);
				if (f(nr,nc,nk) + 1 < dp[r][c][k])
					dp[r][c][k] = f(nr,nc,nk);//, from[r][c][k]={nr,nc,nk};
			}
			dp[r][c][k] += 1;
		}
	}
	return dp[r][c][k];
}
/*
void print (int r, int c, int k)
{
	de(r), de(c), de(k), de(dp[r][c][k]), dd;
	int nr=from[r][c][k].r;
	int nc=from[r][c][k].c;
	int nk=from[r][c][k].k;
	if (nr||nc||nk) print(nr,nc,nk);
}
*/

signed main() { 
	while (cin >> n >> m)
	{
		memset(dp,-1,sizeof(dp));
		memset(id,0,sizeof(id));
		cnt=0, fin=0;
		rep(i,1,n)
		{
			rep(j,1,m)
			{
				char c; cin >> c;
				if (c == '#') id[i][j] = ++cnt, fin|=(1<<cnt);
				if (c == 'L') opr=i, opc=j;	
			}
		}
		cout << f(opr,opc,0) << endl;	
//		print(opr,opc,0);
	}
}
