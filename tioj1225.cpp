#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define fi first
#define se second
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0;

int aliv[N], to[N], from[N], w[N];
Pq< Pii,vector<Pii>,greater<Pii> > pq; //min_part, id

inline void build()
{
	for (int i=1; i<=n; i++) aliv[i] = 1;
	for (int i=0; i<n; i++) to[i] = i+1;
	for (int i=1; i<=n; i++) from[i] = i-1;
	for (int i=0,j=to[i]; j!=0; i=j,j=to[j])
		pq.pb( Pii{min( w[from[i]],w[from[j]]), j} );
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> w[i];
	build();
	for (int t = n; t>1; t--)
	{
		Pii k = pq.top();
		if (!aliv[k.
	}
}

