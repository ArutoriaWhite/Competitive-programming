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


int t, n, owo[N], mx, mn, m;

int main()
{
	akiyama;
	cin >> t;
	while (t--)
	{
		mx = -1e9, mn = 1e9, m = -1e9;
		cin >> n;
		for (int i=0; i<n; i++) cin >> owo[i];
		for (int i=0; i<n; i++)
			if (owo[i]!=-1)
				if ((i>=1&&owo[i-1]==-1) || (i<n-1&&owo[i+1]==-1))
					mx = max(mx,owo[i]), mn = min(mn,owo[i]);
		for (int i=0; i<n; i++)
			if (owo[i] == -1)
				owo[i] = (mx+mn)>>1;
		for (int i=1; i<n; i++)
		{
			m = max( m, abs(owo[i]-owo[i-1]));
		}
		cout << m << ' ' << (mx+mn)/2 << '\n';
	}
}
