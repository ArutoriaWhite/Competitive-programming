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
const int INF=0x7f7f7f7f, N = 1e5+10;

struct rec {int u, d, l, r;} recs[N];
int n, x, y, res = -1;

inline bool in (int x, int y, rec r)
{
	return r.l<=x&&x<=r.r && r.d<=y&&y<=r.u;
}

int main()
{
	cin >> n;
	for (int i=0,l,d,w,h; i<n; i++)
	{
		cin >> l >> d >> w >> h;
		recs[i] = {d+h,d,l,l+w};
	}
	cin >> x >> y;
	for (int i=n-1; i>=0; i--)
	{
		if (in(x,y,recs[i]))
		{
			res = i+1;
			break;
		}
	}
	cout << res << '\n';
}
