#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6+10;

int np[N], gs[N];

signed main()
{
	XinAi
	for (int i=2; i<N; i++)
	{
		if (!np[i])
		{
			for (int j=i*i; j<N; j+=i) np[j]=1;
			for (int j=i; j<N; j*=i) gs[j]=1;
		}
	}
	for (int i=2; i<N; i++) gs[i]+=gs[i-1];
	int n;
	while (cin >> n)
	{
		cout << gs[n] << '\n';
	}
}

