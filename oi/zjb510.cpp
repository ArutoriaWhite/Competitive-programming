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
const int INF=0x7f7f7f7f, N = 20;

int cnt, n;

inline int dfs (int y, int mid, int lq, int rq, int lr, int rr, int qu, int rt)
{
	if (y==n)
		return 1;
	int res = 0;
	if (qu > 0)
		for (int x=0,k=1; x<n; x++,k<<=1)
			if (!((mid|lq|rq)&k))
				res += dfs (y+1, mid|k, (lq|k)<<1, (rq|k)>>1, (lr|k)<<1, (rr|k)>>1 ,qu-1, rt);
	if (rt > 0)
		for (int x=0,k=1; x<n; x++,k<<=1)
			if (!((mid|lr|rr)&k))
				res += dfs (y+1, mid|k, (lq|k)<<1, (rq|k)>>1, lr<<1, rr>>1, qu, rt-1);
	return res;
}

int main()
{
	akiyama;
	int a, b;
	cin >> a >> b;
	n = a+b;
	cout << dfs(0,0,0,0,0,0,a,b) << '\n';
}
