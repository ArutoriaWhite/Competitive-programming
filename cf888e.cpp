#include <vector>
#include <algorithm>
using namespace std;
const int N = 40;

vector<int> dp[N];
int w[N], m, n;

inline void sol()
{
	dp[n].push_back(0);
	for (int i=n-1; i>=0; i--)
	{
		for (auto v: dp[i+1])
		{
			dp[i].push_back((v+w[i])%m);
			dp[i].push_back(v);
			unique(dp[i].begin(),dp[i].end());
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> w[i], w[i]%=m;
	sol();
	cout << *max_element(dp[0].begin(),dp[0].end()) << '\n';
	
}
