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
const int INF=0x7f7f7f7f, N = 1e5;

double h, s, v, l, k, n, g=10, EPS, ttop, tbot;
int res = 0;

inline double tin (int i)
{
	return ((s-i)/v);
}
inline double tout (int i)
{
	return (s-i+l)/v;
}

int main()
{
	akiyama;
	cin >> h >> s >> v >> l >> k >> n;
	ttop = sqrt((h-k)*2/g), tbot = sqrt(h*2/g), EPS = 1e-4/v;
	for (int i=0; i<n; i++)
	{
		if (ttop<=tout(i)||fabs(ttop-tout(i)<EPS))
			if (tin(i)<=tbot||fabs(tin(i)-tbot)<EPS)
				res++;
	}
	cout << res << '\n';
}

