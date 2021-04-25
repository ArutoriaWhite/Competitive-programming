#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int n;
int idx[N], w[N], p1[N], p2[N];
map<int,int> mp;

int cmp (int i, int j)
{
	if (p1[i] != p1[j])
		return p1[i] > p1[j];
	return p2[i] < p2[j];
}

signed main()
{
	ShinraTensei
	cin >> n;
	rep(i,1,n) cin >> w[i];
	rep(i,1,n) cin >> p1[i];
	rep(i,1,n) cin >> p2[i];
	rep(i,1,n) idx[i] = i;

	sort(idx+1, idx+1+n, cmp);
	mp[-1] = 0;
	rep(i,1,n)
	{
		int ww = w[idx[i]];
		int p = p2[idx[i]];
		auto upb = mp.upper_bound(p);
		int w = (prev(upb)->ss + ww);
		mp[p] = w;
		upb = mp.upper_bound(p);
		while (upb!=mp.end() && upb->ss <= mp[p])
			upb = mp.erase(upb);
	}
	cout << mp.rbegin()->ss << '\n';
}
