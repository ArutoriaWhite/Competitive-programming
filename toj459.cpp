#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
const int N = 210;

queue<int> qx, qy;
int fow[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int a[N][N], dep[N][N], n, m, sx, sy, k, owo[N];
unordered_set<int> dp[2];

signed main()
{
	XinAi
    cin >> n >> m >> sx >> sy >> k;
    rep(i,0,n-1) rep(j,0,m-1) cin >> a[i][j];

    qx.push(sx), qy.push(sy);
	dep[sx][sy] = 1;
	dp[0].insert(0);
    
    while (!qx.empty())
    {
        int x=qx.front(), y=qy.front(), d=dep[x][y];
        qx.pop(), qy.pop();
		if (!owo[d])
		{
			dp[d&1].clear();
			for (auto i: dp[(d-1)&1])
					dp[d&1].insert(i);
			owo[d] = 1;
		}
		for (auto i: dp[(d-1)&1])
		{
			if (i+a[x][y] == k || i==k)
			{
				cout << "Lucky!!\n";
				return 0;
			}
			else if (i+a[x][y] < k)
			{
				dp[d&1].insert(i+a[x][y]);
			}
		}
		if (d > 200) continue;
		for (int i=0,vx,vy; i<4; i++)
		{
			vx = x+fow[i][0], vy = y+fow[i][1];
			if (vx<0 || vy<0 || vx>=n || vy>=m || a[vx][vy]<0 || dep[vx][vy]>0) continue;
			dep[vx][vy] = d+1;
			qx.push(vx), qy.push(vy);
		}
    }
	cout << "Unlucky..\n";
}
