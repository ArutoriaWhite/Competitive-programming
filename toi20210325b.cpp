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

signed main()
{
	int n;
	while (cin >> n, n)
	{
		cout << "The parity of ";
		string s;
		int cnt = 0;
		while (n>0) s += "01"[n&1], cnt+=n&1, n>>=1;
		reverse(s.begin(), s.end());
		cout << s <<  " is " << cnt << " (mod 2).\n";
	}
}
