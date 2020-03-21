#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f;

struct ele { int h=0, cnt=0; };
vector<ele> sta;
int n;
ll res;

int main()
{
	akiyama;
	sta.reserve(1000000);
	cin >> n;
	for (int i=0,x,c; i<n; i++)
	{
		cin >> x, c=1;
		while (!sta.empty() && sta.back().h <= x)
		{
			if (sta.back().h == x)
				c += sta.back().cnt;
			res += sta.back().cnt;
			sta.pop_back();
		}
		if (!sta.empty()) res++;
		sta.pb( {x,c} );
	}
	cout << res*2 << '\n';
}
