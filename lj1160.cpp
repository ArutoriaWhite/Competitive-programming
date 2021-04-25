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

const int N = 1e5+10;

list<int>::iterator pos[N];
list<int> L;
int n, m, vis[N];

signed main()
{
	pui
	cin >> n;
	L.push_back(1), pos[1] = L.begin();
	rep(i,2,n)
	{
		int k, p; cin >> k >> p;
		pos[i] = L.insert((p? ++pos[k]:pos[k]),i);
	}	
	cin >> m;
	while (m--)
	{
		int x; cin >> x;
		if (!vis[x]) L.erase(pos[x]), vis[x] = 1;
	}
	for (auto it=L.begin(); it!=L.end(); it++)
	{
		cout << *it << " \n"[(++it==L.end())];
	}
}
