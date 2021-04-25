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
#define low(x) (x&(-x))
using namespace std;
typedef pair<int,int> pii;

int n, x, t;

signed main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> x;
		int a=0, b=0, k=(1<<n);
		if (x == 0)
		{
			cout << 1 << ' ' << 1 << endl;
			continue;
		}
		for (int i=x; i; i-=low(i)) a++;
		b = low(x)-1;
		cout << a+1 << ' ' << k-b << endl;
	}
}
