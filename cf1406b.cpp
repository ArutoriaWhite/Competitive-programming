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

int t, n, zero;
vector<int> pos, neg;

signed main()
{
	SakuraMyWife
	cin >> t;
	while (t--)
	{
		pos.clear();
		neg.clear();
		zero = 0;
		cin >> n;
		rep(i,1,n)
		{
			int x;
			cin >> x;
			if (x>0) pos.pb(x);
			if (x<0) neg.pb(x);
			if (x==0) zero=1;
		}
		int ans = (zero? 0 : -2e18);
		sort(pos.begin(), pos.end(), [](int i, int j){return i>j;});
		sort(neg.begin(), neg.end());
		for (int p=1; p<=5; p+=2)
		{
			if (p > pos.size() || 5-p>neg.size()) continue;
			int res=1;
			for (int i=0; i<p; i++) res *= pos[i];
			for (int i=0; i<5-p; i++) res *= neg[i];
			ans = max(ans, res);
		}
		reverse(pos.begin(), pos.end());
		reverse(neg.begin(), neg.end());
		for (int p=0; p<=5; p+=2)
		{
			if (p > pos.size() || 5-p>neg.size()) continue;
			int res = 1;
			for (int i=0; i<p; i++) res *= pos[i];
			for (int i=0; i<5-p; i++) res *= neg[i];
			ans = max(ans, res);
		} 
		cout << ans << '\n';
	}
}