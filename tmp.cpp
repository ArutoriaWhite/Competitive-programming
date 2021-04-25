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

 int add (int a, int b)
{
	do
	{
		int tmp = a&b;
		a = a^b;
		b = tmp<<1;
	} while (b);
	return a;
}

signed main()
{
	int a, b;
	cin >> a >> b;
	cout << add(a,b) << endl;
}
