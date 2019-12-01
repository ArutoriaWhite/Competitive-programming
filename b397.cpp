#include<iostream>
#include<cstring>
using namespace std; 

int const maxL=40;

string a, b; 
int n, m, u;

int dp[maxL][maxL], used[maxL][maxL];
inline void init()
{
	n = a.size(), m=b.size();
	memset(dp,-1,sizeof(dp));
}
int lcs (int i, int j)
{
	if (used[i][j]<u)
	{
		used[i][j] = u;
		if (i==n || j==m)
		{
			dp[i][j] = 0;
		}
		else if (a[i]==b[j])
		{
			dp[i][j] = lcs(i+1,j+1)+1;
		}
		else
		{
			if (a[i]<b[j])
			{
				dp[i][j] = max(lcs(i,j+1),lcs(i+1,j));
			}
			else
			{
				dp[i][j] = max(lcs(i+1,j),lcs(i,j+1));
			}
		}
	}
	return dp[i][j];
}

int main()
{
	int T;
	cin >> T;
	for (u=1; u<=T; u++)
	{
		cin >> a >> b;
		init();
		cout << lcs(0,0) << '\n';
	}
}
