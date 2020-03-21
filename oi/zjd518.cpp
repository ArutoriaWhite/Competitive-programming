#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
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
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0;

Umap<string,int> vis;
int cnt, n;
string s;

int main()
{
	akiyama;
	while (cin >> n)
	{
		vis.clear(), cnt=0;
		while (n--)
		{
			cin >> s;
			if (!exi(s,vis))
				cout << "New! " << (vis[s]=++cnt) << "\n";
			else
				cout << "Old! " << vis[s] << "\n";
		}
	}
}
