#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string pre, in;
int n, l[N], r[N];

int dfs (int l, int r, int l2, int r2)
{
    int rt = pre[l];
    int m;
    for (int i=l2; i<r2; i++)
        if (in[i] == rt)
        {
            m = i;
            break;
        }
    int llen = m - l2;
    l[rt] = dfs(l+1,l+1+llen,l2,m);
    r[rt] = dfs(l+l+llen,r,m+1,r2);
}
void print (int u)
{
    if (u == 0) break;
    
}
int main()
{
    cin >> pre >> in;
    int rt = dfs(0,n,0,n);
    print(rt);
}