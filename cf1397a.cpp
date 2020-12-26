#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

int cnt[200];

signed main()
{
	XinAi
	int t;
	cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		string s;
		rep(i,1,n)
		{
			cin >> s;
			for (int i=0; i<s.size(); i++)
				cnt[s[i]]++;
		}
		int f=0;
		for (int i=0; i<200; i++)
			f |= cnt[i]%n;
		cout << (f? "NO" : "YES") << '\n';
	}
}
