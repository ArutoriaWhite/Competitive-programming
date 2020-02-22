#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 6;

string keys[N], val[N], root, tar;
int m = 0;
queue<string> qs;
queue<int> qd;
set<string> vis;

inline bool same (const string &rul, const string &s, int l, int r)
{
	for (int i=0,j=l; j<r; i++,j++)
		if (rul[i]!=s[j]) return 0;
	return 1;
}
inline string change (int repl, const string &s, int l, int r)
{
	string res;
	for (int i=0; i<l; i++) res += s[i];
	res += val[repl];
	for (int i=r,len=s.size(); i<len; i++) res += s[i];
	return res;
}
inline int bfs()
{
	qs.push(root);
	qd.push(0);
	vis.insert(root);
	
	while (!qd.empty())
	{
		string s = qs.front(); qs.pop();
		int d = qd.front(); qd.pop();
		if (s==tar) return d;
		if (d>=10) continue;
		
		for (int i=0; i<m; i++)
		{
			for (int l=0,r=keys[i].size(),len=s.size(); r<=len; l++,r++)
			{
				if (same(keys[i],s,l,r))
				{
					string v = change(i,s,l,r);
					if (exi(v,vis)) continue;
					vis.insert(v);
					qs.push( v );
					qd.push( d+1 );
				}
			}
		}
	}
	return -1;
}

inline void test_same()
{
	string rul, s;
	int l, r;
	while (cin >> rul >> s)
	{
		for (int i=0,len=s.size(); i<len; i++) cout << setw(3) << s[i];
		cout << '\n';
		for (int i=0,len=s.size(); i<len; i++) cout << setw(3) << i;
		cout << '\n';
		cin >> l >> r;
		de( same(rul,s,l,r) ), dend;
	}
}

int main()
{
	akiyama;
	cin >> root >> tar;
	while (cin >> keys[m] >> val[m]) m++;
	int res = bfs();
	if (res == -1) cout << "NO ANSWER!\n";
	else cout << res << '\n';
}
