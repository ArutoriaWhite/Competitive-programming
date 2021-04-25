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

const int N = 1010;

int dis[N][N], w[N][N], t, n, m;
int sh[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dijks()
{
	priority_queue< pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>> > q;
	dis[1][1] = w[1][1];
	q.push({w[1][1],make_pair(1,1)});
	while (q.size())
	{
		int i = q.top().ss.ff;
		int j = q.top().ss.ss;
		int d = q.top().ff;
		q.pop();
		rep(k,0,3)
		{
			int ni = i+sh[k][0];
			int nj = j+sh[k][1];
			if (ni<1 || ni>n || nj<1 || nj>m) continue;
			if (dis[ni][nj] > d+w[ni][nj])
			{
				dis[ni][nj] = d+w[ni][nj];
				q.push({dis[ni][nj],make_pair(ni,nj)});
			}
		}
	}
}

signed main()
{
	pui
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		rep(i,1,n)
			rep(j,1,m)
				cin >> w[i][j], dis[i][j] = 1e18;
		dijks();
		cout << dis[n][m] << endl;
	}
}
