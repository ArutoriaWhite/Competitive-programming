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

const int N = 1e7+10;
int mdv[N];

void sieve()
{
	for (int i=2; i<N; i++)
	{

	}
}
pii pfac (int l, int r, map<int,int> &res)
{

}
int legal (map<int,int> &mot, map<int,int> &son)
{
	
}

signed main()
{
	sieve();
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		map<int,int> fac1, fac2;
		if (pfac(a,b,fac1) == pfac(c,d,fac2) && legal(fac1,fac2))
			cout << "DA" << endl;
		else 	
			cout << "NE" << endl;
	}
}
