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
const int INF=0x7f7f7f7f, N = 1e4+10;

priority_queue<int,vector<int>,greater<int>> pq;
int n, res;

int main()
{
	cin >> n;
	for (int i=0,x; i<n; i++)
		cin >> x, pq.push(x);
	for (int a,b; pq.size()>1; )
	{
		a = pq.top(), pq.pop();
		b = pq.top(), pq.pop();
		res += a+b;
		pq.push(a+b);
	}
	cout << res << '\n';
}
