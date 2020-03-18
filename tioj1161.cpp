#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 1e6+10;

int T, n, res, s[N], a[N], id[N], k;
Pq<int,vector<int>,less<int> > pq;

int main()
{
	akiyama;
	cin >> T;
	while (T--)
	{
		while (!pq.empty()) pq.pop();
		res = INF;
		cin >> n >> k;
		for (int i=0; i<n; i++)
			cin >> s[i] >> a[i], id[i] = i;
		sort(id,id+n,[](int x, int y){return s[x]<s[y];});
		for (int i=0; i<n; i++)
		{
			pq.push(a[id[i]]);
			if (pq.size() == k)
			{
				res = min( res, pq.top()+s[id[i]]);	
				pq.pop();
			}
		}
		cout << res << '\n';
	}	
}


