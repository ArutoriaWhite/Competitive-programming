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
const int INF=0x7f7f7f7f, N = 5e5+10;

int ouo[N], pos[N], n, q;
set<int> s;
vector<int> v;

inline void print()
{
	cout << "ouo: ";
	for (int i=1; i<=n; i++) cout << ouo[i] << ' ';
	cout << '\n';
	cout << "pos: ";
	for (int i=1; i<=n; i++) cout << pos[i] << ' ';
	cout << '\n';
	cout << "dif pos: ";
	for (auto x: v) cout << x << ' ';
	cout << '\n';
}

inline void mswap (int a, int b)
{
	swap(pos[ouo[a]],pos[ouo[b]]);
	swap(ouo[a],ouo[b]);
	if (ouo[a] == a) s.erase(a);
	else s.insert(a);
	if (ouo[b] == b) s.erase(b);
	else s.insert(b);
}
inline void recover(int l, int r)
{
	int res = 0;
	v.clear();
	auto beg = s.lower_bound(l);
	auto ed = s.upper_bound(r);
	for (auto it = beg; it!=ed; it++) v.pb(*it);
	for (auto t: v)
		if (ouo[t]!=t)
			mswap(t,pos[t]), res++;
	cout << res << '\n';
}
int main()
{
	akiyama;
	cin >> n >> q;
	for (int i=1; i<=n; i++) ouo[i] = i, pos[i] = i;
	for (int i=0,opr,a,b; i<q; i++)
	{
		cin >> opr >> a >> b;
		if (opr == 1) mswap(a,b);
		else recover(a,b);
	}
}
