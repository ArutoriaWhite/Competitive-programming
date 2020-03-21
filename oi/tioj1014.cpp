#include <iostream>
#include <cstring>
using namespace std;
const int N = 16;

int dp[N][1<<N], t[N], n;

int main()
{
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> t[i];
	
	memset(dp,0x7f,sizeof(dp));
	dp[0][0] = 1;
    
	for (int s=0; s<(1<<n); s++)
		for (int i=0; i<n; i++)
			if (s&(1<<i))
				for (int k=0,x; k<n; k++)
				{
                    x = dp[k][s&~(1<<i)] + abs(k-i);
					dp[i][s] = min( dp[i][s],(x-1/t[i]+1)*t[i]);
				}
                    
	int res = 0x7f7f7f7f;
	for (int i=0; i<n; i++)
		res = min( res, dp[i][(1<<n)-1]);
	cout << res << '\n';
}
