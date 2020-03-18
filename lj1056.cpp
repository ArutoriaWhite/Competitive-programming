#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define fi first
#define se second
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=0x3f3f3f3f, MIN = 0xc0c0c0c0, N = 1000;

int m, n, k, l, d, verid[N], verw[N], horid[N], horw[N];

int main()
{
	cin >> m >> n >> k >> l >> d;
	for (int i=0; i<d; i++)
	{
		int x, y, xp, yp;
		cin >> y >> x >> yp >> xp;
		if (y == yp) verw[min(x,xp)]++;
		else horw[min(y,yp)]++;
	}
	for (int i=0; i<m; i++) horid[i] = i+1;
	for (int i=0; i<n; i++) verid[i] = i+1;
	sort(verid,verid+n,[](int a, int b){return verw[a]>verw[b];});
	sort(horid,horid+m,[](int a, int b){return horw[a]>horw[b];});
	sort(verid,verid+l);
	sort(horid,horid+k);
	for (int i=0; i<k; i++)
		cout << horid[i] << "\n "[i+1<k];
	for (int i=0; i<l; i++)
		cout << verid[i] << "\n "[i+1<l];
}
