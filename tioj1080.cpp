#include<iostream>
#include<algorithm>
#include<memory.h>
#define lowbit(x) (x&-x)
using namespace std;
const int N = 1e5+10;

int n, arr[N], ord[N];
int BIT[N<<1];

inline void init()
{
    memset(BIT,0,sizeof(BIT));
    for (int i=0; i<n; i++)
        ord[i] = i;
}
inline bool cmp (int i, int j)
{
    return arr[i]>arr[j];
}


inline int sum (int q)
{
    int res = 0;
    for ( ; q>0; q-=lowbit(q)) res += BIT[q];
    return res;
}
inline int query (int l, int r)
{
    return sum(r)-sum(l);
}
inline void modify (int p, int x)
{
    for (p++; p<=n; p+=lowbit(p)) BIT[p]+=x;
}

int main()
{

    char opr;
    int l, r;
    while (cin >> opr)
    {
        if (opr == 'm')
        {
            cin >> l;
            modify(l);
        }
        else
        {
            cin >> l >> r;
            cout << query(l,r) << '\n';
        }
    }

    while (cin >> n)
    {
        init();
        for (int i=0; i<n; i++)
            cin >> arr[i];
        sort(ord,ord+n);

        int res=0;
        for (int i=0,j; i<n; i++)
        {
            for (j=i; arr[ord[j]]==arr[ord[i]]; j++);
            res += (j-i)*(query(ord[i]));
            modify(ord[i],(j-i));
        }
        cout << res << '\n';       
    }
}