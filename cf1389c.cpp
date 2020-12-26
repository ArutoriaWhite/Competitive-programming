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
const int N = 2e5+10;

int arr[N];

signed main()
{
	XinAi
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		int n, ans=0x3f3f3f3f;
		cin >> s;
		n = s.size();
		for (int i=0; i<n; i++) arr[i]=s[i]-'0';
		for (int i=0; i<10; i++)
		{
			for (int j=0; j<10; j++)
			{
				int p=0, res=0;
				while (p<n)
				{
					while (p<n && arr[p]!=i) p++,res++;
					p++;
					while (p<n && arr[p]!=j) p++,res++;
					p++;
				}
				//de(i), de(j), de(res), dd;
				if ((n-res)&1 && i!=j) res++;
				ans = min(res, ans);
			}
		}
		cout << ans << '\n';
	}
}
