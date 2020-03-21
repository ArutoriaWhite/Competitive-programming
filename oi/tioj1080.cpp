#include <iostream>
#include <algorithm>
#include<memory.h>
#define int long long
using namespace std;
#define lowbit(x) (x&-x)
const int N = 1e5+10;

int BIT[N], n;
inline int sum (int p)
{
    int res = 0;
    for ( ; p>0; p-=lowbit(p)) res += BIT[p];
    return res;
}
inline void modify (int p, int x)
{
    for (p++; p<=n; p+=lowbit(p)) BIT[p]+=x;
}

int arr[N], id[N], t=0;
inline bool cmp (int i, int j)
{
    return (arr[i]==arr[j])? (i>j) : (arr[i]>arr[j]);
}

signed main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);

    while (cin >> n)
    {
        if (n==0) break;
        memset(BIT,0,sizeof(BIT));

        for (int i=0; i<n; i++)
            cin >> arr[i], id[i] = i;
        sort(id,id+n,cmp);

        int res=0;
        for (int i=0; i<n; i++)
        {
            res += sum(id[i]);
            modify(id[i],1);
        }
        cout << "Case #" << ++t << ": " << res << "\n";
    }
}