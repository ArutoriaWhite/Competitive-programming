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
const int INF=0x7f7f7f7f, N = 3e4+10;

int qwq[N], w, n, res;
int main()
{
	akiyama;
	cin >> w >> n;
	for (int i=0; i<n; i++)
		cin >> qwq[i];
	sort(qwq,qwq+n);
	for (int i=0,j=n; i<j; j--)
	{
		for (int k=w-qwq[j-1]; k>=qwq[i]; k-=qwq[i],i++);
		res++;
	}
	cout << res << '\n';
}
