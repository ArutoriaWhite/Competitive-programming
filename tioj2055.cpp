#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

struct node
{
    int l,r,m;
} st[100001<<2];

void pull(int x)
{
    st[x].m=min(st[x<<1].m,st[x<<1|1].m);
}

void build(int x,int l,int r)
{
    st[x].l=l,st[x].r=r,st[x].m=1e9;
    if (l==r) cin>>st[x].m;
    else
    {
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        pull(x);
    }
}

int query(int x,int l,int r)
{
    int L=st[x].l,R=st[x].r;
    if(L>=l&&R<=r) return st[x].m;
    else
    {
        int mid=(L+R)>>1,m=1e9;
        if(l<=mid) m=min(m,query(x<<1,l,r));
        if(r>mid) m=min(m,query(x<<1|1,l,r));
        return m;
    }
}

int main()
{
    AC
    int n;
    cin>>n;
    build(1,1,n);
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(1,l,r)+1<<'\n';
    }
}
