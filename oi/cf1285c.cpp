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
const int INF=0x7f7f7f7f, M = 1e6+100;

inline ll gcd (ll a, ll b)
{
	ll tmp;
	while (b!=0)
		tmp = b, b  = a%b, a = tmp;
	return a;
}

int main()
{
	ll n, k, mn = 1e17, resa, resb;
	cin >> n;
	k = sqrt(n)+1;
	for (ll a=1,b; a<=k; a++)
	{
		if (n%a!=0) continue;
		b = (n/gcd(n/a,a))/a;
		if ((a*b)%n==0)
		{
			if (max(a,b)<mn) mn = max(a,b);
			resa = a, resb = b;
		}
	}
	cout << resa << ' ' << resb << '\n';
}

