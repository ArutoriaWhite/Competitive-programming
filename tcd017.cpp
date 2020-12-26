#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

int qpow (int i, int j, int m)
{
    int res=1;
    for (; j; j>>=1,i=i*i%m)
        if (j&1) res=res*i%m;
    return res;
}

signed main()
{
    int n, p;
    cin >> n >> p;
    while (n--)
    {
        int x;
        cin >> x;
        cout << qpow(x,p-2,p) << ' ';
    }
    cout << '\n';
}