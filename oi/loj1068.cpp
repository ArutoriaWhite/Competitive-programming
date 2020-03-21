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
const int INF=0x7f7f7f7f, N = 5010;

int ord[N], id[N], sco[N], n, m, r;
inline bool cmp (int a, int b)
{
	if (sco[a]!=sco[b]) return sco[a]>sco[b];
	return id[a]<id[b];
}

int main()
{
	cin >> n >> m, r = m*1.5;
	for (int i=0; i<n; i++)
		cin >> id[i] >> sco[i], ord[i] = i;
	sort(ord,ord+n,cmp);
	for (int t=r; sco[ord[r]]==sco[ord[t-1]]; r++);
	cout << sco[ord[r-1]] << ' ' << r << '\n';
	for (int i=0; i<r; i++)
		cout << id[ord[i]] << ' ' << sco[ord[i]] << '\n';
}
