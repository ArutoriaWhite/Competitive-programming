#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10, M=1e7+10;

int p[M];

string name[N];
int sz[N], cb[N], mx[N], sm[N], id[N], idx[N];
int n;

inline int cmp (int i, int j)
{
	if (sz[i]!=sz[j]) return sz[i]>sz[j];
	if (cb[i]!=cb[j]) return cb[i]>cb[j];
	if (mx[i]!=mx[j]) return mx[i]>mx[j];
	if (sm[i]!=sm[j]) return sm[i]>sm[j];
	return id[i]>id[j];
}

signed main()
{
	XinAi
	for (int i=2; i<M; i++)
		if (!p[i])
			for (int j=i; j<M; j+=i) if(!p[j]) p[j]=i;
	while (cin >> n)
	{
		rep(i,1,n) cin >> name[i] >> id[i];
		rep(i,1,n) sz[i]=mx[i]=sm[i]=0,cb[i]=1,idx[i]=i;
		rep(i,1,n)
		{
			int x=id[i];
			while (x>1)
			{
				int pp = p[x], cnt=0;
				while (!(x%pp)) cnt++,x/=pp;
				mx[i] = max(mx[i], pp);
				cb[i] *= cnt+1;
				sm[i] += cnt;
				sz[i]++;
			}
		}
		sort(idx+1, idx+1+n, cmp);
		rep(i,1,n) cout << name[idx[i]] << '\n';
	}
}
/*
6
goblin_king 101
overlord 30
firefox 36
queen_harpy 51
slime_princess 44
red-black(alraune) 91
*/