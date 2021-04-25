#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 2010, X = 500;

struct Big
{
	int num[X];
	Big (int x)
	{
		memset(num,0,sizeof(num));
		for (int i=0; x>0; x/=10, i++)
			num[i] = x%10;
	}
	Big(){memset(num,0,sizeof(num));}
	void operator += (Big y)
	{
		for (int i=0; i<X; i++)
			num[i] += y.num[i], num[i+1] += num[i]/10, num[i]%=10;
	}
	void print()
	{
		int flag = 0;
		for (int i=X-1; i>=0; i--)
		{
			if (num[i] != 0) flag = 1;
			if (flag) cout << num[i];
		}	
		cout << endl;
	}
};

int a[N], b[N], n, m, id[200];
string s1, s2;
Big dp[2][2];

signed main()
{
	id['A'] = 1, id['T'] = 2;
	id['C'] = 0, id['G'] = 3;
	cin >> n >> m >> s1 >> s2;
	for (int i=0; i<n; i++) a[i+1] = id[s1[i]];
	for (int i=0; i<m; i++) b[i+1] = id[s2[i]];
	for (int i=0; i<=n; i++) dp[i&1][0] = Big(1);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			dp[i&1][j&1] = Big();
			if (a[i]+b[j] == 3) dp[i&1][j&1] += dp[(i+1)&1][(j+1)&1];
			dp[i&1][j&1] += dp[(i+1)&1][j&1];
		}
	}
	dp[n&1][m&1].print();
}

/*

dp[i][j]: how many ways 1~i match to 1~j

dp[i][j]: 
	+= dp[i-1][j-1] (if a[i]+b[i]==3)
	+= dp[i-1][j] 
	dp[i][0] = 1

   */
