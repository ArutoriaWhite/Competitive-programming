#include <iostream>
#include <algorithm>
#include<memory.h>
#define int long long
using namespace std;
#define lowbit(x) (x&-x)
const int N = 1e5+10;

int st[N<<1], n;

void modify (int p, int x)
{
	for (p=p+n; p>0; p>>=1)
		st[p] += x;
}
int query (int l, int r)
{
	int ans = 0;
	for (l+=n,r+=n; l<r; l>>=1,r>>=1)
	{
		if (l&1) ans += st[l++];
		if (r&1) ans += st[--r];
	}
	return ans;
}

int arr[N], id[N], t=0;
inline bool cmp (int i, int j)
{
    return (arr[i]==arr[j])? (i>j) : (arr[i]>arr[j]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n)
    {
        if (n==0) break;
		memset(st,0,sizeof(st));

        for (int i=0; i<n; i++)
            cin >> arr[i], id[i] = i;
        sort(id,id+n,cmp);

        int res=0;
        for (int i=0; i<n; i++)
        {
            res += query(0,id[i]);
            modify(id[i],1);
        }
        cout << "Case #" << ++t << ": " << res << "\n";
    }
}
