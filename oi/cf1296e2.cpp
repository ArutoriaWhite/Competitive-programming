#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+10;

int n, id[N], st[N<<1], res=-1;
string s;

inline void modify (int p, int x)
{
	for (st[p+=n]=x; p>1; p>>=1)
		st[p>>1] = max(st[p],st[p^1]);
}
inline int query (int l, int r)
{
	int res=0;
	for (l+=n,r+=n; l<r; l>>=1,r>>=1)
	{
		if (r&1) res = max(res, st[--r]);
		if (l&1) res = max(res, st[l++]);
	}
	return res;
}
inline bool cmp (int a, int b)
{
	if (s[a] == s[b]) return a<b;
	return s[a]<s[b];
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	for (int i=0; i<n; i++)	id[i]=i;
	sort(id,id+n,cmp);
	for (int i=0; i<n; i++)
	{
		int k = query(id[i],n);
		res = max(res,k+1);
		modify(id[i],k+1);
	}
	cout << res << '\n';
	for (int i=0; i<n; i++)
		cout << st[i+n] << "\n "[i+1<n];
}
