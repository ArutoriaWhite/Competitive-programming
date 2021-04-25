#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
#define endl '\n';
using namespace std;
typedef pair<int,int> pii;

const int N = 70, V = 55;

int cnt[V], n, total, mx, mn=1e9, x;
int cap;

void dfs (int sum=0, int fin=total/cap, int p=mn)
{
	if (fin == 0)
	{
		cout << cap;
		exit(0);
	}
	if (sum==cap)
	{
		dfs(0,fin-1,mn);
		return;
	}	

	for (int i = min(cap-sum,p); i>=mn; i--)
	{
		if (cnt[i])
		{
			cnt[i]--;
			dfs(sum+i,fin,i);
			cnt[i]++;
			if (sum==0 || i==cap-sum) break;
		}
	}
}

signed main()
{
	pui
	cin >> n;
	rep(i,1,n)
	{
		cin >> x;
		if (x <= 50)
		{
			cnt[x]++;
			total += x;
			mx = max(mx, x);
			mn = min(mn, x);
		}
	}
	
	rep(i,mx,total/2)
		if (total%i == 0)
			cap = i, dfs();
	cout << total;
}
