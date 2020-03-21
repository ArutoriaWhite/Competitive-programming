#include <bits/stdc++.h>
#define int long long
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
const int INF=0x7f7f7f7f, N = 1e3+10;

int owo[N], id[N], n, sum, res;

inline bool cmp (int a, int b)
{
	if (owo[a] !=owo[b])
		return owo[a]<owo[b];
	return a<b;
}

signed main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> owo[i], id[i] = i;
	sort(id+1,id+1+n,cmp);
	for (int i=1; i<=n; i++)
		cout << id[i] << "\n "[i+1<=n];
	for (int i=1; i<=n; i++)
		sum = sum+owo[id[i-1]], res+=sum;
	cout << fixed << setprecision(2) << (double)res/(n) << '\n';

}
