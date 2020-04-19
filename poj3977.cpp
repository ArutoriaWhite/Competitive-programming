#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define exi(x,s) (s.find(x)!=s.end())
#define fi first
#define se second
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define lowbit(x) (x&-x)
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 40;

ll arr[N], l[N*N], r[N*N], lcnt[N*N], rcnt[N*N], cnt, res;
int n, m;

inline void gen (int sh, ll *x, ll *y)
{
	for (int i=0,j=0,s=0,c=0; i<(1<<m); j=i,i++)
	{	
		for (int del=j&(~i); del>0; del-=lowbit(del))
			s -= arr[__lg(lowbit(del))+sh], c--;
		for (int add=(~j)&i; add>0; add-=lowbit(add))
			s += arr[__lg(lowbit(add))+sh], c++;
		x[i-1] = s, y[i-1] = c;
	}
}

int main()
{
	yukari;
    while (cin >> n && n)
    {
		m = n>>1, cnt=0, res=1e18;
		for (int i=0; i<n; i++)
			cin >> arr[i];
		gen(0,l,lcnt), gen(m,r,rcnt);
		sort(r,r+n);
		for (int i=0; i<(1<<m); i++)
			de(l[i]), de(r[i]), dend;
		for (int i=0; i<(1<<m); i++)
		{
			int j = upper_bound(r,r+n,-l[i])-r;
			if (j>0 && abs(l[i]+r[j-1])<res)
					res = abs(l[i]+r[j-1]), cnt = min(cnt, lcnt[i]+rcnt[j-1]);
			if (j<n && abs(l[i]+r[j])<res)
					res = abs(l[i]+r[j]), cnt = min(cnt, lcnt[i]+rcnt[j]);
		}
		cout << res << ' ' << cnt << '\n';
	}

}
