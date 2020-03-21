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
const int INF=0x7f7f7f7f;

int n, h, res;

int main()
{
	akiyama;
	cin >> n;
	for (int i=0,pre=0; i<n; i++,pre=h)
	{
		cin >> h;
		res += max(h-pre,0);
	}
	cout << res << '\n';
}

