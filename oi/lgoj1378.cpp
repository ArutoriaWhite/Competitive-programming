#include <bits/stdc++.h>
#include <math.h>
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
double PI = acos(-1);

int n;
double u, d, l, r, nod[10][2], rad[10];
bool vis[10];

inline double dis (double x1, double y1, double x2, double y2)
{
	return sqrt( pow(abs(x1-x2),2) + pow(abs(y1-y2),2) );
}
inline double max_radius (int x)
{
	double res = 0;
	for (int i=0; i<n; i++)
		if (i!=x)
			res = min(res, dis(nod[x][0],nod[x][1],nod[i][0],nod[i][1])-rad[i]);
	res = min(res, abs(nod[x][0]-l));
	res = min(res, abs(nod[x][0]-r));
	res = min(res, abs(nod[x][1]-d));
	res = min(res, abs(nod[x][1]-u));
	return res;
}

inline double dfs (int d)
{
	if (d == n) return 0;
	double res = 0;
	for (int i=0; i<n; i++)
	{
		if (vis[i]) continue;
		rad[i] = max_radius(i), vis[i] = 1;
		res = max(rad[i]*rad[i]*PI+dfs(d+1), res);
		rad[i] = 0,      vis[i] = 0;
	}
	return res;
}

int main()
{
	cin >> n;
	cin >> l >> u >> r >> d;
	for (int i=0; i<n; i++)
		cin >> nod[i][0] >> nod[i][1];
	cout << fixed << setprecision(0) << abs(l-r)*abs(u-d)-dfs(0) << '\n';
}
