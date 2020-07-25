#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10, M = 110;

int n, m, u[N][M], x[N][M], cnt[N], res, s;

int main()
{
	Eriri
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> u[i][j] >> x[i][j];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cnt[i] += u[i][j];
	
	cin >> s;
	for (int i=0; i<n; i++)
	{
		res = (res + x[i][s])%20123;
		if (cnt[i] > 0)
			for ( int c = x[i][s]%cnt[i]+cnt[i]; c; s=(s+1)%m)
				if (u[i][s]) c--;
		s = (s-1+m)%m;
	}
	cout << res << '\n';
}