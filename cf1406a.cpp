#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1000;

int cnt[N], t, n;

signed main()
{
	SakuraMyWife
	cin >> t;
	while (t--)
	{
		mem(cnt, 0);
		cin >> n;
		rep(i,1,n)
		{
			int x;
			cin >> x;
			cnt[x]++;
		}
		int m1=-1;
		for (int i=0; i<N&&cnt[i]>=2; i++) m1 = i;
		int m2=-1;
		for (int i=0; i<N&&cnt[i]>=1; i++) m2 = i;
		cout << m1+m2+2 << '\n';
	}
}