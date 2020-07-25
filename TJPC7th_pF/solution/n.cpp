#include <iostream>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
using namespace std;
const int N = 100001;

int n, m;
int a[N<<1], b[N<<1];
int nex0[N], nex1[N], len0, len1;
int ans, best_pos;

inline void link1()
{
	int head = -1, i, pre;
	for (i=1; i<=m; i++)
	{
		if (b[i] == 0)
		{
			if (head == -1) head = pre = i;
			else nex0[pre] = i, pre = i;
		}
	}
	nex0[pre] = head;
}
inline void link0()
{
	int head = -1, i, pre;
	for (i=m; i>0; i--)
	{
		if (b[i] == 1)
		{
			if (head == -1) head = pre = i;
			else nex1[pre] = i, pre = i;
		}
	}
	nex1[pre] = head;
}
inline void init_len()
{
	for (int i=1; i<=m; i++)
	{
		if (b[i] == 1)
			len1 = max(len1, a[i] - a[1]);
		else
			len0 = max(len0, (a[1]-a[i]+n)%n);
	}
}

int main()
{
	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		cin >> a[i] >> b[i];
	}
	link0();
	link1();
	init_len();
	ans = max(len0,len1);
	best_pos = a[1];
	for (int i=2; i<=m; i++)
	{
		len0 += a[i]-a[i-1];
		len1 -= a[i]-a[i-1];
		if (b[i] == 0)
			len0 = (len0 - a[nex0[i]] + a[i]+ 2*n)%n;
		if (b[i-1] == 1)
			len1 = (len1 + a[i-1] - a[nex1[i-1]]+n)%n;
		if (max(len0,len1) < ans)
		{
			ans = max(len0,len1);
			best_pos = a[i];
		}
	}
	cout << best_pos << ' ' << ans << '\n';
}
/*
6 4
1 0
3 0
4 1
5 1
*/