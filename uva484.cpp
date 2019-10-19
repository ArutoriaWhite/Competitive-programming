#include<iostream>
#include<algorithm>
using namespace std;
#define maxN 10000000

int ans[maxN][2], rear=0, id[maxN], num[maxN];

inline bool cmp( int a, int b)
{
    return (num[a]==num[b])? (a<b) : (num[a]<num[b]);
}

int main()
{
    int n=0;
    while (cin>>num[n])
    {
        id[n]=n;
        n++;
    }

    sort( id, id+n, cmp);
    for( int i=0; i<n; i++)
    {
        ans[id[i]][0] = num[id[i]];
        int j;
        for( j=i; num[id[j]]==num[id[j+1]]; j++);
        ans[id[i]][1] = j-i+1;
        i=j;
    }
    for( int i=0; i<n; i++)
    {
        if (ans[i][0]==0) continue;
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
}