// dp: dis(i,j,k) = min( dis(i,k,k-1)+dis(k,j,k-1), dis(i,j,k-1) );
#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;

int dis[N][N], T, Q, n, m;

inline void init()
{
	memset(dis,0x3f,sizeof(dis));
	for (int i=0; i<N; i++)
		dis[i][i] = 0;
}

inline void floyd()
{
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				dis[i][j] = min( dis[i][k]+dis[k][j], dis[i][j] );
}

int main()
{
	cin >> T;
	while (T--)
	{
		init();
		cin >> n >> m;
		for (int i=0,f,t,w; i<m; i++)
		{
			cin >> f >> t >> w;
			dis[f][t] = w;
		}
 		floyd();

		cin >> Q;
		for (int i=0,f,t; i<Q; i++)
		{
			cin >> f >> t;
			if (dis[f][t] == 0x3f3f3f3f) cout << "-1\n";
			else cout << dis[f][t] << '\n';
		}
	}
}
