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
const int N = 1e5+10;

int n, q, a[N], cnt[N], emt[N], res[N], k;
struct Qry {int l, r, id;} qry[N];

int cmp (Qry i, Qry j)
{
	if (i.l/k != j.l/k)
		return i.l/k < j.l/k;
	return i.r < j.r;
}

void add (int &ans, int x)
{
	cnt[emt[x]]--;
	emt[x]++;
	cnt[emt[x]]++;
	if (emt[x] > ans)
		ans = emt[x];
}
void del (int &ans, int x)
{
	cnt[emt[x]]--;
	emt[x]--;
	cnt[emt[x]]++;
	if (cnt[ans] <= 0)
		ans = emt[x];
}

signed main()
{
	ShinraTensei
	cin >> n >> q; k = sqrt(n);
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) cin>> qry[i].l >> qry[i].r, qry[i].id=i;
	sort(qry+1,qry+1+q,cmp);

	int ans=0, l=0, r=0;
	rep(i,1,q)
	{
		while (r < qry[i].r) add(ans, a[++r]);
		while (r > qry[i].r) del(ans, a[r--]);
		while (l > qry[i].l) add(ans, a[--l]);
		while (l < qry[i].l) del(ans, a[l++]);
		res[qry[i].id] = ans;
	}
	rep(i,1,q) cout << res[i] << '\n';
}
