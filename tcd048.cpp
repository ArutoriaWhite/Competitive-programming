#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

priority_queue<int, vector<int>, greater<int>> pq;

signed main()
{
	int n, tot=0, cost=0;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		pq.push(x);
		tot += x;
	}

	while (pq.size() > 1)
	{
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		cost += x+y;
		pq.push(x+y);
	}
	
	cout << tot << '\n' << cost << '\n';
}
