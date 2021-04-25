#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

string s;
int forbi[][2] = {{1,9},{2,8},{3,7},{4,6},{5,0}};

int tail()
{
	for (int i=s.size()-1; i>=0; i--)
	{
		if ('0'<=s[i] && s[i]<='9')
		{
			return s[i] - '0';
		}
	}
}

signed main()
{
	cin >> s;
	if (s[0]=='M'&&s[1]=='D'&&s[2]=='A')
	{
		int x = tail();
		rep(i,0,4)
		{
			if (x == forbi[i][0] || x == forbi[i][1])
			{
				cout << 1 << ' ';
			}
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
	else
	{
		rep(i,1,5) cout << 1 << ' '; dd
	}
}
