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
const int INF=0x7f7f7f7f, N = 15;

string n;
int k, vis[N];
vector<int> adj[N];
struct BigNum
{
	int num[40], M = 35;
	BigNum ()
	{
		mem(num,0), num[0] = 1;
	}
	void mult (int x)
	{
		int tmp = 0;
		for (int i=0; i<=M; i++)
		{
			num[i]*=x, num[i]+=tmp;
			tmp = num[i]/10, num[i]%=10;
		}
	}
	void print ()
	{
		int flag=0;
		for (int i=M; i>=0; i--)
		{
			flag |= (num[i]!=0);
			if (flag) cout << num[i];
		}
		cout << '\n';
	}
} res;

int dfs (int u)
{
	vis[u] = 1;
	int r=1;
	for (auto v: adj[u])
		if (!vis[v]) r += dfs(v);
	return r;
}

int main()
{
	cin >> n >> k;
	for (int i=0,x,y; i<k; i++)
	{
		cin >> x >> y;
		adj[x].pb(y);
	}
	for (int i=0,len=n.size(); i<len; i++)
	{
		mem(vis,0);
		res.mult(dfs(n[i]-'0'));
	}
	res.print();
}
