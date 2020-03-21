#include<iostream>
using namespace std;

int G[110][110];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				cin >> G[i][j];
			}
		}
		bool flag=0;
		for (int j=0; j<n-1; j++)
		{
			for (int i=1; i<m; i++)
			{
				if (G[j][i] == G[j+1][i-1])
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag) cout << "Yes\n";
		else cout << "No\n";

	}
}
