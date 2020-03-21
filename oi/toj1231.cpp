#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb emplace_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7f7f7f7f;

int n;
priority_queue<pii> pq; // time, car

int main()
{
	cin >> n;
	for (int i=0,c,t; i<n; i++)
		cin >> c >> t, tim.pb(t), pq.push( {c,t} );
	sort(tim.begin(), tim.end()), unique(tin.begin(), tim.end());
}
