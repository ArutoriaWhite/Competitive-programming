#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6+10;

vector<int> val;
int n, m, a[N], cpos[N];

int st[N<<1];
int query (int l, int r)
{
	int ans = 0;
	for (l+=n,r+=n+1; l<r; l>>=1,r>>=1)
	{
		if (l&1) ans += st[l++];
		if (r&1) ans += st[--r];
	}
	return ans;
}
void setto (int p, int x)
{
	for (st[p+=n]=x; p>1; p>>=1)
		st[p>>1] = st[p]+st[p^1];
}

int bs (int p) // search a min index i such that st[0]+...+st[i]==p
{
	if (query(0,n-1) < p) return -1;
	int i=-1, s=n;
	while (s)
	{
		if (i+s>=n || query(0,i+s)>=p) s>>=1;
		else i += s;
	}
	return i+1;
}

signed main()
{
	pui
	cin >> n >> m;
	rep(i,1,m) cin >> a[i];
	a[m+1] = 1e9;

	int las = 1;
	rep(i,1,n)
	{
		int x; cin >> x;
		if (x < 0)
		{
			for (int i=1; i<las; i++)
				setto(cpos[i], 0);
			for (int i=1; i<las; i++)
			{
				cpos[i] = bs(a[i]);
				if (cpos[i] < 0)
				{
					las = i;
					break;
				}
			}
		}
		else
		{
			setto(val.size(),1);
			if (query(0,val.size())==a[las]) cpos[las]=val.size(), las++;
			val.pb(x);
		}
		/*
		de(las), de(a[las]), de(query(0,n-1)), dd
		rep(i,1,m) de(i), de(cpos[i]), dd
		rep(i,0,n-1) de(i), de(query(i,i)), dd
		*/
	}
	for (int i=0; i<val.size(); i++)
		if (query(i,i)) cout << val[i];
	if (query(0,n-1)==0) cout << "Poor stack!\n";
}


