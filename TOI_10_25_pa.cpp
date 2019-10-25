#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxN 100000

int id[maxN];
int arr[maxN];
int n, m;

inline void init()
{
    memset( arr, 0, sizeof(arr));
    for( int i=0; i<n; i++)
    {
        id[i] = i;
    }
}

inline bool cmp( int a, int b)
{
    return (arr[a]==arr[b])? (a<b) : (arr[a]>arr[b]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    init();
    for( int i=0; i<m; i++)
    {
        int j, x;
        cin >> j >> x;
        arr[j] += x;
    }
    sort( id, id+n, cmp);
    for( int i=0; i<n; i++)
    {
        cout << id[i] << ' ' << arr[id[i]] << '\n';
    }
}