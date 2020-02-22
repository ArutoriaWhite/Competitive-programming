#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define INF = 0x7f
#define mem(a,x) memset(a,x,sizefo(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define DE(x) cout << ":: " << #x << '=' << x << '\n'
typedef long long ll;
using namespace std;

string s;
int m, n, res;
umap<char,int> total, less;

inline int fac (int k)
{
	int res = 1;
	for (int i=1; i<=k; res=(res*i),i++);
	return res;
}

int main()
{
	cin >> s;
	n = s.size();

	for (int i=0; i<n; i++)
	{
		total.clear(), less.clear();
		for (int j=i; j<n; j++)
		{
			if (s[j]<s[i])
		}
	}
	}
