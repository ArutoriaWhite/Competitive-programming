#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back()
#define pui ios::sync_with_stdio(), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

string ch = "0123456789ABCDEF";
string s;

signed main()
{
	cin >> s;
	cout << s[0];

	for (int i=1; i<s.size(); i++)
	{
		int owo = 0;
		if ('0'<=s[i]&&s[i]<='9')
			owo = s[i]-'0';
		else
			owo = s[i] - 'A'+10;
		cout << ch[15-owo];
	}
	cout << '\n';
}
