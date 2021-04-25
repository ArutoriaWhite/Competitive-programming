#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

/*

enum primes as p	
	count p in (a-1)!, b!, (c-1)!, d! as fa, fb, fc, fd
	check if (fd-fc >= fb-fa)
   */

const int N = 1e7+10;  

int np[N];
vector<int> primes;

void sieve()
{
	for (int i=2; i<N; i++)
	{
		if (!np[i])
		{
			primes.pb(i);
		}
		for (int j=i*i; j<N; j+=i)
			np[j] = 1;
	}
}
int fac (int x, int p)
{
	int ans = 0;
	for (; x; ans += x /= p);
	return ans;
}
	
signed main()
{
	sieve();
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, d, flag=1;
		cin >> a >> b >> c >> d;
		for (auto p: primes)
		{
			int fa = fac(a-1,p), fb = fac(b,p);
			int fc = fac(c-1,p), fd = fac(d,p);
			if (fd-fc < fb-fa)
			{
				flag = 0;
				break;
			}
		}
		cout << (flag? "DA":"NE") << endl;
	}
}


