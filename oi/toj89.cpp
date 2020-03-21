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
const int INF=0x7f7f7f7f, N = 5e5+10;

int p[N<<1], x, y, n;
string s1, s2, s3;

inline int find (int x) { return (x==p[x]? x : p[x]=find(p[x])); }
inline void U (int a, int b) { p[find(a)] = find(b); }

int main()
{
	akiyama;
	cin >> n;
	for (int i=1; i<=n*2; i++) p[i] = i;
	while (cin >> s1 >> s2 >> s3 >> x >> y)
	{
		int fx = find(x), fy = find(y), bx = find(x+n), by = find(y+n);
		if (s1[0]=='y' && s3[0]=='f')
		{
			if (fx == by) cout << "angry\n";
			else U(fx,fy), U(bx,by);
		}
		if (s1[0]=='y' && s3[0]=='e')
		{
			if (fx == fy) cout << "angry\n";
			else U(fx,by), U(fy,bx);
		}
		if (s1[0]=='a' && s3[0]=='f')
			cout << (fx==fy? "yeap\n" : "nope\n");
		if (s1[0]=='a' && s3[0]=='e')
			cout << (fx==by? "yeap\n" : "nope\n");
	}
}
