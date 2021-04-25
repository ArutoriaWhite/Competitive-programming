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

int np[N];

int rev (int n)
{
	int res = 0;
	while (n) res*=10, res += n%10, n/=10;
	return res;
}

signed main()
{
	pui
	np[0] = np[1] = 1;
	for (int i=2; i<N; i++)
		for (int j=i*i; j<N; j+=i)
			np[j] = 1;
	int n;
	while (cin >> n)
	{
		if (np[n]) cout << n << " is not prime.\n";
		else if ((!np[rev(n)]) && (!np[n]) && (rev(n)!=n)) cout << n << " is emirp.\n";
		else cout << n << " is prime.\n";
	}
}
