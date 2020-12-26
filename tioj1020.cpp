#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 40;

int nex[N] = {1}, n, cnt;
vector<int> res;

void dfs (int u)
{
    if (u > n)
    {
        vector<int> v;
        v.clear();
        cnt++;
        for (int i=0,j=nex[0]; i!=1; i=j,j=nex[j])
            v.pb(i);
        v.pb(1);
        if (res.size()==0) res=v;
        else
        {
            for (int i=0; i<n; i++)
            {

                if (v[i]>res[i])
                {
                    res = v;
                    break;
                }
                else if (v[i]<res[i]) break;
            }
        }
        return;
    }
    for (int i=0,j=nex[0]; i!=1; i=j,j=nex[j])
    {
        if (u%(i+j)==0)
        {
            nex[i] = u;
            nex[u] = j;
            dfs(u+1);
            nex[i] = j;
        }
    }
}

signed main()
{
    SakuraMyWife
    cin >> n;
    dfs(2);
    cout << cnt << '\n';
    for (auto x: res)
        cout << x << ' ';
    cout << '\n';
}

