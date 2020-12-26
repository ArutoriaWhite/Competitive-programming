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
typedef int nakiri[2][2];
typedef int (*ayame)[2];
const int M = 1000000007;

int beg[2] = {0,1};
nakiri swit = 
{
    {0, 1},
    {1, 1}
};
nakiri unit = 
{
    {1, 0},
    {0, 1}
};
nakiri m0, m1, m2;

void mul (ayame x, ayame y, ayame res)
{
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            res[i][j] = 0;
            for (int k=0; k<2; k++)
            {
                res[i][j] = (res[i][j]+x[k][j]*y[i][k]%M)%M;
            }
        }
    }
}

ayame qpow (int k)
{
    memcpy(m0,unit,sizeof(m0));
    memcpy(m2,swit,sizeof(m2));
    ayame res=m0, tmp=m1, x=m2;
    while (k>0)
    {
        if (k&1)
        {
            mul(res,x,tmp);
            swap(tmp,res);
        }
        k>>=1;
        mul(x,x,tmp);
        swap(tmp,x);
    }
    return res;
}

signed main()
{
    ShinraTensei
    int n;
    while (cin >> n && n>0)
    {
        ayame owo = qpow(n);
        int res = owo[1][0];
        cout << res << '\n';
    }
}