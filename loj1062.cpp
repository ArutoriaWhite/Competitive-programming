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
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 1e3+10;

ull owo[N];
int r=1, k, n;

inline ull qpow (ull x, int y)
{
	ull res=1, t[]={1,x};
	for ( ; y>0; res*=t[y&1],t[1]*=t[1],y>>=1);
	return res;
}

int main()
{
	cin >> k >> n;
	n++;
	for (int i=0; r<n; i++)
		for (int j=0,t=r; j<t&&r<n; j++)
			owo[r++] = owo[j] + qpow(k,i);
	cout << owo[r-1] << '\n';
}
