#include <iostream>
#include <vector>
#include <cstring>
#define DE cout << " ::"
using namespace std;
const int N = 210;

vector<int> adj[N];
int colo[N], n;
string s;

inline bool dfs (int u, int p)
{
	for (auto v: adj[u])
	{
		if (v==p) continue;
		if (colo[v] == -1)
		{
			colo[v] = !colo[u];
			if (!dfs(v,u)) return 0;
		}
		else if (colo[v]==colo[u])
			return 0;
	}
	return 1;
}
inline bool dfs_all()
{
	for (int i=0; i<n; i++)
		if (colo[i]==-1)
		{
			colo[i]=0;
			if (!dfs(i,-1)) return 0;
		}
	return 1;
}
inline void print()
{
	for (int i=0; i<n; i++)
	{
		for (auto v: adj[i])
			DE << v;
		DE << '\n';
	}
}
inline void init()
{
	memset(colo,-1,sizeof(colo));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	init();
	cin >> n >> s;
	for (int i=0; i<n; i++)
		for (int j=i-1; j>=0; j--)
			if (s[i]<s[j]) adj[i].push_back(j), adj[j].push_back(i);
	if (dfs_all())
	{
		cout << "YES\n";
		for (int i=0; i<n; i++) cout << colo[i];
		cout << '\n';
	}
	else cout << "NO\n";
}
