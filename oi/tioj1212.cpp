#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 510;

int dis[N][N], n, m, res;

int main()
{
	while (cin >> n >> m && (n||m))
	{
		memset(dis,INF,sizeof(dis));
		res = INF;
		for (int i=0,u,v; i<m; i++)
			cin >> u >> v, dis[u][v] = 1;
		for (int k=1; k<=n; k++)
			for (int i=1; i<=n; i++)
				for (int j=1; j<=n; j++)
					dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
		for (int i=1; i<=n; i++)
			res = min(res,dis[i][i]);
		cout << ((res==INF)? 0 : res) << '\n';
	}
}
