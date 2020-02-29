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
const int INF=0x7f7f7f7f;

string dics[10], s;
int dp[500][50], m, p, k, n;

inline bool comp (int i, const string &q)
{
	for (int j=i,x=0,len=q.size(); x<len; j++,x++)
		if (s[j] != q[x]) return 0;
	return 1;
}
inline int calc (int l, int r)
{
	for (int i=l; i<r; i++)
		for (int j=0; j<m; j++)
			if (comp(i,dics[j])) res++;
	return res;
}
int sol (int i, int d)
{
	if (d==0) return 0;
	if (dp[i][d] == -1)
		for (int j=i+1; j<=(n-d+1); j++)
			dp[i][d] = max(dp[i][d], sol(j,d-1)+calc(i,j));	
	return dp[i][d];
}

int main()
{
	cin >> p >> k;
	string line;
	while (p--) cin >> line, s+=line;
	cin >> m;
	for (int i=0; i<m; i++) cin >> dics[i];

	n = s.size();
	mem(dp,-1);

	cout << sol(0,k) << '\n';
}
