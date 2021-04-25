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

int sum, n;

signed main()
{
	cin >> n;
	rep(i,2,n)
	{
		int x; cin >> x;
		sum += x;
	}
	int i = -1, s = 200;
	while (s)
	{
		if ((i+s)*n >= (sum+(i+s))) s>>=1;
		else i += s;
	}
	cout << i+1 << endl;
}
