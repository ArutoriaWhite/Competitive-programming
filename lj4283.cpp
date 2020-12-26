#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 55;

string a, b, c;
int n, ans;

void calc (string A, string B, string C)
{
	int lcp=0, lcp2=0;
	for (int i=0; i<min(SZ(A),SZ(B)); i++,lcp=i)
	{
		if (A[i] != B[i])
		{
			break;
		}
	}
	for (int i=0; i<min(SZ(B),SZ(C)); i++,lcp2=i)
	{
		if (B[i] != C[i])
		{
			break;
		}
	}
	if (lcp < lcp2) return;
	int res = SZ(C) - lcp2 + lcp - lcp2;
	res += SZ(A)-lcp + SZ(B) - lcp;
	ans = min(ans, res);
}

signed main()
{
	cin >> n >> a >> n >> b >> n >> c;
	ans = 1e9;
	calc(a,b,c);
	calc(a,c,b);
	calc(b,c,a);
	cout << ans << '\n';
}
