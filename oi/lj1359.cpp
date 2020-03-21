#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF = 0x3f3f3f3f, MIN = 0xc0c0c0c0, N = 210;

int dis[N][N], n;

int main()
{
	cin >> n;
	mem(dis,INF);
	for (int i=1; i<=n-1; i++)
		for (int j=i+1; j<=n; j++)
			cin >> dis[i][j];
	for (int i=1; i<=n; i++)
		dis[i][i] = 0;
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				dis[i][j] = min( dis[i][j], dis[i][k]+dis[k][j]);
	cout << dis[1][n] << '\n';
}
