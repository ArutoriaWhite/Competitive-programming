#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 30;

vector<int> G[N];
int in[N], tmpin[N], inq[N], n, m;
string ans;

void findu (int &u, int &st)
{
	u=-1;
	for (int i=0; i<n; i++)
	{
		if (inq[i] || tmpin[i]!=0) continue;
		if (u>=0)
		{
			st=0;
			return;
		}
		u = i;
	}
	st = (u==-1? -1 : 1);
}

int check()
{
	for (int i=0; i<n; i++) tmpin[i]=in[i];
	memset(inq,0,sizeof(inq));
	ans="";
	int sure=1;
	for (int i=0,u,st; i<n; i++)
	{
		findu(u,st); //normal 1 findu: no zero: -1 multiple zero 0
		if (st == -1) return -1;
		if (st == 0) sure=0;
		ans += u+'A';
		for (auto v: G[u]) tmpin[v]--;
		inq[u] = 1;
	}
	return sure;
}

signed main()
{
	XinAi
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		string s;
		cin >> s;
		int u = s[0]-'A', v=s[2]-'A', flag=0;
		for (auto i: G[u])
			if (i==v) flag=1;
		if (flag) continue;
		G[u].push_back(v);
		in[v]++;
		int owo=check();
		if (owo==1)
		{
			cout << "Sorted sequence determined after " << i+1 << " relations: " << ans << '\n';
			return 0;
		}
		else if (owo==-1 || u==v)
		{
			cout << "Inconsistency found after " << i+1 << " relations.\n";
			return 0;
		}
	}
	cout << "Sorted sequence cannot be determined.\n";
}
