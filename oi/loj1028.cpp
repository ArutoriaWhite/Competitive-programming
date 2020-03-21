#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb emplace_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f;

int f[1010];

int main()
{
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) f[i] = 1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i/2; j++)
			f[i] += f[j];
	cout << f[n] << '\n';
}
