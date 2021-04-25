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

const int N = 25e3+10;

vector<int> G[N];
int colo[N], idx[N], T, n, m, deg[N];

signed main()
{
	cin >> T;
	while (T--)
	{
		memset(colo,0,sizeof(colo));
		cin >> n >> m;
		rep(i,1,n) idx[i] = i;
		rep(i,1,m)
		{
			int u, v;
			cin >> u >> v;
			G[u].pb(v);
			G[v].pb(u);
			deg[u]++, deg[v]++;
		}
		sort(idx+1,idx+1+n,[](int i, int j){return deg[i]>deg[j];});
		while (1)
		{
			int ex = 1;
			rep(i,1,n)
			{
				int x = idx[i];
				int cnt[5] = {0};
				for (auto v: G[x])
					cnt[colo[v]]++;
				rep(j,1,4)
				{
					if (cnt[j] < 2)
					{
						colo[x] = j;
						break;
					}
				}
				if (colo[x] == 0) 
				{
					ex = 0;
					break;
				}
			}

			if (ex)
			{
				rep(i,1,n) cout << (char)('a'+colo[i]-1) << "\n "[i+1<=n];
				break;
			}
			else
				random_shuffle(idx+1,idx+1+n);
		}
	}
}
