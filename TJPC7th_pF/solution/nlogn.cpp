#include <iostream>
#include <algorithm>
#define de(x) cout << #x << '=' << x << '\n'
#define dd cout << '\n';
using namespace std;
const int N = 100001;

int n, m, anti_clk[N], clk[N], a[N], r1 = 0, r2 = 0, ans = 1e9, ans_num;

inline bool cmp (int i, int j)
{
	return i > j;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int b;
		cin >> a[i] >> b;
		if (b==0)
		{
			clk[r1++] = a[i];
			clk[r1++] = a[i]+n;
		}
		else
		{
			anti_clk[r2++] = a[i];
			anti_clk[r2++] = a[i]+n;
		}
	}
	sort(clk,clk+r1);
	sort(anti_clk,anti_clk+r2,cmp);
	for (int i=0; i<m; i++)
	{
		int x = 0, y = 0;
		if (r1 > 0)
			x = (a[i] - *upper_bound(clk,clk+r1,a[i]) + n)%n;
		if (r2 > 0)
			y = (*upper_bound(anti_clk,anti_clk+r2,a[i]+n,cmp) -a[i] + n)%n;
		if (max(x,y) < ans)
		{
			ans = max(x,y);
			ans_num = a[i];
		}
	}
	cout << ans_num << ' ' << ans << '\n';
}
/*
6 4
1 0
2 0
3 0
4 0
*/