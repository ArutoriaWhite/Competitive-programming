#include <iostream>
#define DE cout << " ::"
using namespace std;
const int N = 1e3;

int dp[(1<<3)], vit[N], w[N], n;

int main()
{
	cin >> n;
	string s;
	for (int i=0; i<n; i++)
	{
		cin >> w[i];
		cin >> s;
		for (int j=0; j<s.size(); j++)
			vit[i] |= 1<<(s[j]-'A');
	}
	for (int s=6; s>=0; s--)
	{
		dp[s] = 1e9;
		for (int i=0; i<n; i++)
			dp[s] = min( dp[s], dp[s|vit[i]]+w[i]);
	}

	if (dp[0]==1e9) cout << "-1\n";
	else cout << dp[0] << '\n';
}
