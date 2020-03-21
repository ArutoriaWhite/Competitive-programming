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
const int INF=0x7f7f7f7f, N = 1e8+10;

int primes[50000000], r, isntp[N], n, q;

inline void build ()
{
	for (int i=2; i<N; i++)
	{
		if (!isntp[i]) primes[r++] = i;
		for (int j=0; j<r&&(i*primes[j]<N); j++)
		{
			isntp[ i*primes[j] ] = 1;
			if (!(i%primes[j])) break;
		}
	}
}

int main()
{
	akiyama;
	cin >> n >> q;
	build();
	for (int i=0,k; i<q; i++)
		cin >> k, cout << primes[k-1] << '\n';
}
