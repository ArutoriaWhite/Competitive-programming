#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7f7f7f7f;

priority_queue< int, vector<int>, less<int> > pq;
vector< pair<int,int> > foods; // time, second;
int n, k, pre, t;
ll res;

int main()
{
	akiyama;
	cin >> n;
	for (int i=0,c,x; i<n; i++)
		cin >> c >> x, foods.pb( {x,c} );
	cin >> t;
	foods.pb( {0,0} );

	sort(foods.begin(), foods.end(), [](pii a, pii b)->bool{return a.first > b.first;} );
	for (auto x: foods)
	{
		x.first = min(x.first, t);
		if (x.first != t)
		{
			pre = t, t = x.first;
			int cnt=0;
			for (int i=0; !pq.empty() && i<pre-t; i++)
				res += pq.top(), pq.pop(), cnt++;
			res -= pre-t-cnt;
		}
		if (x.first == t)
			pq.push(x.second);
	}
	cout << res << '\n';
}
