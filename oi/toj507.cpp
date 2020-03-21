#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define INF = 0x7f
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define DE(x) cout << #x << '=' << x << '\n';
typedef long long ll;
using namespace std;
const int N = 510;

int res=0, n, aa[N], bid[N];

inline bool can (int a, int b, int f)
{
	if (f==0) return a <= b;
	else return a>=b;
}

int main ()
{
	akiyama;
	cin >> n;
	for (int i=1,a,b; i<=n; i++)
	{
		cin >> a >> b;
		aa[i] = a, bid[b] = i;
	}

	for (int i=1,f=0; i<=n; i++)
		if (!can(i,bid[aa[i]],f)) f = !f, res++;
	cout << res << '\n';
}

