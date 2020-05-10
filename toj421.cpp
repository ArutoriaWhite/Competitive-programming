#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
const int N = 1e7+10;

int n, q;
LL st[N<<1];
inline void build()
{
	for (int i=0; i<n; i++) cin >> st[i+n];
	for (int i=n-1; i>0; i--) st[i] = max(st[i<<1],st[i<<1|1]);
}
inline LL query(int l, int r)
{
	LL res = 0;
	for (l+=n,r+=n; l<r; l>>=1,r>>=1)
	{
		if (l&1) res = max(res, st[l++]);
		if (r&1) res = max(res, st[--r]);
	}
	return res;
}

int main()
{
    Eriri
    cin >> n >> q;
    build();
    for (int i=0,l,r; i<q; i++)
    {
        cin >> l >> r;
        if (l>r) swap(l,r);
        cout << query(l-1,r) << '\n';
    }
}
/*
10 5
4 0 17 13 14 15 6 2 17 10
5 5
5 7
3 9
1 2
1 7
*/