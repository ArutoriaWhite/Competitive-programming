#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int N = 200;

int n, r;
string a, b, res;
bitset<N> apr, pre[N];
char lis[N];

void dfs (int d, bitset<N> has)
{
	if (d==r) cout << res << '\n';
	else
		for (int i=0; i<r; i++)
			if (!has[lis[i]])
				if ((has&pre[lis[i]]) == pre[lis[i]])
				{
					res += lis[i], has[lis[i]] = 1;
					dfs(d+1,has);
					res.erase(prev(res.end())), has[lis[i]]=0;
				}
}
inline void init()
{
	r=0;
	res = "";
	apr.reset();
	for (int i=0; i<N; i++) pre[i].reset();
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> n&&n)
	{
		init();
		cin >> a;
		for (int i=0; i<n-1; i++,a=b)
		{
			cin >> b;
			for (int i=0,len=min(a.size(),b.size()); i<len; i++)
			{
				if (a[i]!=b[i])
				{
					if (!apr[a[i]]) lis[r++] = a[i];
					if (!apr[b[i]]) lis[r++] = b[i];
					apr[a[i]] = apr[b[i]] = 1;
					pre[b[i]][a[i]] = 1;
					break;
				}
			}
		}
		dfs(0,bitset<N>{0});
	}

}
