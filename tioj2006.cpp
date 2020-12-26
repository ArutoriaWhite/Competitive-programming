#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

int cnt[500], tmp[500], n, m;

int legal (int x, int y)
{
	rep(j,1,n) tmp[j] = cnt[j];
	tmp[x]++;
	if (tmp[y] < 2) return 0;
	tmp[y] -= 2;
//	de(x), de(y);
//	rep(i,1,n) cout << tmp[i] << ' ';
//	dd;
	rep(j,1,n-2)
	{
		tmp[j] %= 3;
		if (tmp[j]>0)
		{
			if (tmp[j]<=tmp[j+1] && tmp[j]<=tmp[j+2])
			{
				tmp[j+1] -= tmp[j];
				tmp[j+2] -= tmp[j];
				tmp[j] -= tmp[j];
			}
			else
			{
//				de(x), de(y);
//				rep(i,1,n)
//					cout << tmp[i] << ' ';
//				cout << '\n';
				return 0;
			}
		}
	}
//	de(x), de(y);
//	rep(i,1,n)
//	{
//		cout << tmp[i] << ' ';
//	}
//	dd
	return tmp[n]%3==0 && tmp[n-1]%3==0;
}

signed main()
{
	cin >> n >> m;
	rep(i,1,3*m+1)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}

	//rep(i,1,n) cout << cnt[i] << ' ';
	//cout << '\n';

	int flag=0;
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			if (legal(i,j))
			{
				flag=1;
				cout << i << ' ';
				break;
			}
		}
	}
	if (!flag) cout << "NO";
	cout << '\n';
}
