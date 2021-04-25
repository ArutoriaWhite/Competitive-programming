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

priority_queue<int,vector<int>,greater<int>> pq;
int n;

signed main()
{
	cin >> n;
	while (n--)
	{
		int o, x;
		cin >> o;
		if (o == 1) cin >> x, pq.push(x);
		if (o == 2) cout << pq.top() << endl;
		if (o == 3) pq.pop();
	}
}
