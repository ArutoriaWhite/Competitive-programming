#include<iostream>
using namespace std;
#define maxN (1000000+10)
#define LOG (30)

int st[LOG][maxN];
inline void build( int n)
{
	for (int i=0; i<n; i++)
		cin >> st[0][i];
	for (int j=1; (1<<j)<=n; j++)
		for (int i=0; i+(1<<j)<n; i++)
			st[j][i] = min( st[j-1][i], st[j-1][i+(1<<(j-1))]);
}
inline int query( int l, int r)
{
	int k;
	for (k=0; (1<<k)<=(r-l+1); k++);
	return min( st[k][l], st[k][r-(1<<k)+1]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	build(n);
	for (int i=0; i<n; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << query(l-1,r-1) << '\n';
	}
}
