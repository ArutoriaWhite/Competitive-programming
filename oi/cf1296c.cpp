#include <bits/stdc++.h>
#define DE cout << " ::"
#define EXI(m,x) (m.find(x)!=m.end())
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

map<pii,int> vis;
int sumx[N], sumy[N], n, T, resl, resr, len;
string s;

inline void init()
{
	vis.clear();
	len = 1e9;
	vis[{0,0}] = 0;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while (T--)
	{
		init();
		cin >> n >> s;
		for (int i=1; i<=n; i++)
		{
			sumx[i] = sumx[i-1], sumy[i] = sumy[i-1];
			if (s[i-1]=='U') sumy[i] += 1;
			if (s[i-1]=='D') sumy[i] -= 1;
			if (s[i-1]=='L') sumx[i] -= 1;
			if (s[i-1]=='R') sumx[i] += 1;
			
			pii u = {sumx[i],sumy[i]};
			if (EXI(vis,u))
			{
				int l = vis[u];
				if (i-l < len)
					len = i-l, resl = l, resr = i;
			}
			vis[u] = i;
		}
		
		if (len == 1e9) cout << -1 << '\n';
		else cout << resl+1 << ' ' << resr << '\n';
	}
}

