#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 1e5+10;

int owo[N], qwq[N], n, x, d, T, res;

int main()
{
	akiyama;
	cin >> T;
	while (T--)
	{
		res = 0;
		cin >> n >> x;
		char c;
		for (int i=0; i<n; i++)
			cin >> c, owo[i] = c-'0';
		for (int i=1; i<=n; i++)
			if (owo[i-1] == 0) qwq[i] = qwq[i-1]+1;
			else qwq[i] = qwq[i-1]-1;
	
		if (x==0) res++;
		d = qwq[n];
		for (int i=1; i<=n; i++)
		{
			if (qwq[i] == x && d==0)
			{
				res = -1;
				break;
			}
			if (d!=0)
			{
				double ouo = (x-(double)qwq[i])/(double)d;
				unsigned int OuO = (x-qwq[i])/d;
				if (ouo == OuO) res++;
			}
		}
		cout << res << '\n';
	}
}
