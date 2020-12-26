#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
#define int long long
using namespace std;
typedef pair<int,int> pii;

string s;
vector<int> st;

signed main()
{
	XinAi
	while (cin >> s)
	{
		int lf=0, yuan=0, dep=0;
		for (int i=0; i<SZ(s); i++)
		{
			if (s[i] == '(')
			{
				if(!st.empty()) st.back()++;
				st.push_back(0);
			}
			if (s[i] == ')')
			{
				st.pop_back();
			}
			if (s[i] == '*')
			{
				lf++;
				if(!st.empty()) st.back()++;
			}
			if(!st.empty()) yuan = max(st.back(), yuan);
			dep = max(dep, SZ(st));
		}
		cout << lf << ' ' << dep+1 << ' ' << yuan << '\n';
	}
}

