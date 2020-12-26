#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4+10;

vector<int> adj[N];
int n, colo[N], res;

void dfs (int u)
{
	for (auto v: adj[u])
	{
		if (colo[u]==colo[v]) res++;
		dfs(v);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i=2,p; i<=n; i++)
		cin >> p, adj[p].push_back(i);
	for (int i=1; i<=n; i++)
		cin >> colo[i];
	dfs(1);
	cout << max(1,n-res) << '\n';
}
