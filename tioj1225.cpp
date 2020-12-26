#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;

vector<int> st;

signed main()
{
	XinAi
	int n;
	long long res=0;
	cin >> n;
	rep(i,1,n)
	{
		int x;
		cin >> x;
		while (!st.empty() && x >= st.back())
		{
			res += min(x, (st.size()>1? st[st.size()-2] : (int)2e9));
			st.pop_back();
		}
		st.push_back(x);
	}
	rep(i,0,st.size()-2) res += st[i];
	cout << res << '\n';
}
