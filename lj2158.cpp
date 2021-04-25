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

const int N = 4e4+10;

int md[N], phi[N], n;

signed main()
{
	for (int i=2; i*i<N; i++)
		for (int j=i*i; j<N; j+=i)
			if (!md[j]) md[j] = i;
	for (int i=2; i<N; i++)
		if (!md[i]) md[i] = i;
	cin >> n;
	if (n == 1)
	{
		cout << 0 << endl;
		exit(0);
	}
	int ans = 0;
	for (int i=2; i<n; i++)
	{
		phi[i] = i;
		for (int x=i,y=md[x]; x>1; y=md[x])
		{
			phi[i] = phi[i]*(y-1)/y;
			while (!(x%y)) x /= y;
		}
		ans += phi[i];
	}
	cout << ans*2+3 << endl;
}
