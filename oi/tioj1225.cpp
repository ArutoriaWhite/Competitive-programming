#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define int long long
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 1e6+10;

int sta[N], r, n, res;

signed main()
{
	akiyama;
	cin >> n;
	for (int i=0,x; i<n; i++)
	{
		cin >> x;
		while (r>0 && sta[r-1]<x)
			res += (r>1? min(x,sta[r-2]) : x), r--;
		sta[r++] = x;
	}
	for (int i=r-2; i>=0; i--)
		if (i>=0)
			res += sta[i];
	cout << res << '\n';
}
