#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 20, M = (1<<16);

int n, used[N][M];
double dp[N][M], res = 1e9, pos[N][2];

inline double dis (int i, int j)
{
	return sqrt( pow( pos[i][0]-pos[j][0], 2) + pow( pos[i][1]-pos[j][1], 2));
}
double sol (int u, int vis)
{
	if (used[u][vis] == 0)
	{
		used[u][vis] = 1;
		if (vis == (1<<n)-1) dp[u][vis] = 0;
		else
			for (int i=0; i<n; i++)
				if ((vis&(1<<i)) == 0)
					dp[u][vis] = min(dp[u][vis], sol(i,vis|(1<<i))+dis(u,i));
	}
	return dp[u][vis];
}

inline void test_dis ()
{
	int i, j;
	while (cin >> i >> j)
		de(dis(i,j)), dend;
}
int main()
{
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			dp[i][j] = INF;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> pos[i][0] >> pos[i][1];
	for (int i=0; i<n; i++)
		res = min(res, sol(i,1<<i)+dis(i,n) );
	cout << fixed << setprecision(2) << res << '\n';
}
