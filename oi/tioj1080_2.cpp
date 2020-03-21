#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
const int maxN = 1e5+10;

int n;

int BIT[maxN];

inline int sum( int i)
{
    int s=0;
    for( int j=i; j>0; j-=lowbit(j))
    {
        s+= BIT[j];
    }
    return s;
}

inline void add( int i, int x)
{
    for( int j=i; j<=n; j+=lowbit(j))
    {
        BIT[j] += x;
    }
}

int arr[maxN];
int id[maxN];

inline bool cmp( int a, int b)
{
    return (arr[a] == arr[b])? (a>b) : (arr[a]>arr[b]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> n)
    {
        memset(BIT,0,sizeof(BIT));
        for( int i=1; i<=n; i++)
        {
            cin >> arr[i];
        }
        for( int i=0; i<n; i++)
        {
            id[i] = i+1;
        }
        sort( id, id+n, cmp);

        long long s = 0;
        for( int i=0; i<n; i++)
        {
            s += sum(id[i]-1);
            add( id[i], 1);
        }
        cout << s << '\n';        
    }
}
