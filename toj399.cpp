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
const int N = 1010;

string a, b, c, res, s="0123456789ABCDEF";
int ii[200];

signed main()
{
	for (int i=0; i<s.size(); i++) ii[s[i]] = i;

	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int flag = 0;
	if (a.size() > b.size())
		for (int i=a.size()-1; i>=b.size(); i--) cout << a[i], flag=1;
	else if (b.size() > a.size())
		for (int i=b.size()-1; i>=a.size(); i--) cout << b[i], flag=1;
	for (int i=min(a.size(), b.size())-1; i>=0; i--)
	{
		if (flag==0 && s[ ii[a[i]]^ii[b[i]] ]=='0') continue;   
		flag=1;
		cout << s[ ii[a[i]]^ii[b[i]] ];
	}
	if (flag == 0) cout << '0';
	cout << '\n';
}
