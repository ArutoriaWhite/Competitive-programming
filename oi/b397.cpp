#include<bits/stdc++.h>
using namespace std;
const int maxL = 40;

unordered_set<string> sol[maxL][maxL];
string a, b;
int n, m;

inline bool cmp ( const string *a, const string *b)
{
	return *a < *b;
}

int dp[maxL][maxL], used[maxL][maxL], u;
int lcs (int i, int j)
{
	if (used[i][j]<u)
	{
		used[i][j] = u;
		if (i==n || j==m)
		{
			dp[i][j] = 0;
			sol[i][j].insert("");
		}
		else if (a[i] == b[j])
		{
			dp[i][j] = lcs(i+1,j+1)+1;
			for (auto x: sol[i+1][j+1])
				sol[i][j].insert(a[i]+x);
		}
		else
		{
			int x = lcs(i+1,j), y = lcs(i,j+1);
			if (x>=y)
			{
				dp[i][j] = x;
				for (auto v: sol[i+1][j])
					sol[i][j].insert(v);
			}
			if (y>=x)
			{
				dp[i][j] = y;
                for (auto v: sol[i][j+1])
                    sol[i][j].insert(v);
			}
		}
	}
	return dp[i][j];
}

const string *res[100000+10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (u=1; u<=T; u++)
	{
		cin >> a >> b;
		n = a.size(), m=b.size();
		
		for (auto &x: sol)
			for (auto &y:x)
				y.clear();
				
		lcs(0,0);
		
		int r=0;
		
		cout << "Case #" << u << ": " << sol[0][0].size() << "\n";
		
		for (auto &x: sol[0][0])
			res[r++] = &x;
			
		sort(res,res+r,cmp);
		
		for (int i=0; i<r; i++)
			cout << *(res[i]) << '\n';	
	}
}
