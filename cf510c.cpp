#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 110;

int n, in[200];
string s[N], ans;
vector<int> G[200];
queue<int> q;

int topo()
{
	for (int i='a'; i<='z'; i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		ans += (char)u;
		for (auto v: G[u])
		{
			in[v]--;
			if (in[v]==0) q.push(v);
		}
	}
	for (int i=0; i<200; i++) if(in[i]) return 0;
	return 1;
}

signed main()
{
	XinAi
	cin >> n;
	rep(i,1,n) cin >> s[i];
	rep(i,1,n-1)
	{
		for (int j=0; j<min(SZ(s[i]),SZ(s[i+1])); j++)
			if (s[i][j] != s[i+1][j])
			{
				G[s[i][j]].push_back(s[i+1][j]);
				in[s[i+1][j]]++;
				break;
			}
	}
	cout << (topo()? ans:"Impossible") << '\n';
	
}
