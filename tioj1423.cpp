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
const int N = 360;

int x[N], y[N], n, res;

double calc_f (double x1, double y1, double x2, double y2, double x)
{
	double a = (y1-y2)/(x1-x2);
	double b = y1 - a*x1;
	return a*x + b;
}

signed main()
{
	cin >> n;
	rep(i,1,n) cin >> x[i] >> y[i];
	rep(i,1,n)
	{
		rep(j,i+1,n)
		{
			int cnt1=0, cnt2=0;
			if (x[i] == x[j])
			{
				rep(k,1,n)
				{
					if (x[k]>x[i]) cnt2++;
					else if (x[k]<x[i]) cnt1++;
				}
			}
			else
			{
				rep(k,1,n)
				{
					if (k==i || k==j) continue;
					double f = calc_f(x[i],y[i],x[j],y[j],x[k]);
					if (y[k]-f > 0) cnt1++;
					else if (f-y[k] > 0) cnt2++;
				}
			}
			res += cnt1*cnt2;
		}
	}
	cout << res << '\n';
}

