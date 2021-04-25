#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 10, M = 1e8;

int t, pat[N], cdate[N], ans;
int lim[] = {0,9,9,9,9,1,9,3,9};
int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int np[100000000];
vector<int> primes;

inline int num (int l, int r)
{
	int ans = 0;
	rep(i,l,r)
	{
		ans = ans*10+cdate[i];
	}
	return ans;
}
inline int leap (int x)
{
	if (x%100==0)
		return (x%400==0);
	return x%4==0;
}
inline void sieve()
{
	for (int i=2; i<M; i++)
	{
		if (!np[i])
		{
			primes.pb(i);
		}
		for (auto p: primes)
		{
			if ((long long)p*i >= M) break;
			np[p*i] = 1;
			if (i%p == 0) break;
		}
	}
	np[0] = np[1] = 1;
}

void dfs (int i=1)
{
	if (pat[i] > 0)
	{
		cdate[i] = pat[i];
		dfs(i+1);
	}
	else if (i <= 8)
	{
		if (i == 5)
		{
			if (num(1,4) == 0) return;
		}
		if (i == 7)
		{
			if (num(5,6)<1 || num(5,6)>12) return;
		}
		rep(j,0,lim[i])
		{
			cdate[i] = j;
			dfs(i+1);
		}
	}
	else
	{
		// return if day illegal
		if (leap(num(1,4)) && num(5,6) == 2)
		{
			if (num(7,8)<1 || num(7,8)>29)
				return;
		}
		else 
		{
			if (num(7,8)<1 || num(7,8)>days[num(5,6)])
				return;
		}
		if (!np[num(1,8)] && !np[num(5,8)] && !np[num(7,8)])
			ans++;
	}
}

signed main()
{
	ShinraTensei
	cin >> t;
	sieve();
	while (t--)
	{
		rep(i,1,8)
		{
			char c; cin >> c;
			if (c=='-')
				pat[i] = -1;
			else 
				pat[i] = c-'0';
		}
		ans = 0;
		dfs();
		cout << ans << '\n';
	}
}