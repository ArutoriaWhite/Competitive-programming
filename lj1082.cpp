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

pii exgcd (int a, int b)
{
	if (a==0 || b==0) return (a==0? pii{0,1} : pii{1,0});
	pii nxt = exgcd(b,a%b);
	return {nxt.ss, nxt.ff - (a/b)*nxt.ss};
}

signed main()
{
	int a, b;
	cin >> a >> b;
	pii res = exgcd(a,b);
	cout << (res.ff%b+b)%b << '\n';
}
