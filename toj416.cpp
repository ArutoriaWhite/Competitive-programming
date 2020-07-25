#include<iostream>
#include<memory.h>
using namespace std;
#define N 6
#define M 1000000007
#define int long long
typedef unsigned int akagi[N][N];
typedef unsigned int (*natori)[N];

int fir[N] = {1,1,0,1,0,0};
akagi swit =
{
    {1,1,0,1,0,0},
    {1,0,1,1,0,0},
    {1,0,0,1,0,0},
    {0,0,0,1,1,0},
    {0,0,0,1,0,1},
    {0,0,0,1,0,0},
};
akagi ini =
{
    {1,0,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,1,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,0,1,0},
    {0,0,0,0,0,1}
};
akagi m0,m1,m2;

inline void mul (natori a, natori b, natori res)
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            res[i][j] = 0;
            for (int k=0; k<N; k++)
                res[i][j] = ((a[i][k]*b[k][j])%M + res[i][j])%M;
        }
    }
}

inline natori qpow (int n)
{
    memcpy(m0,swit,sizeof(m0));
    memcpy(m1,ini,sizeof(m1));
    natori a = m0, res = m1, tmp = m2;
    
    while (n>0)
    {
        if (n&1)
        {
            mul(res,a,tmp);
            swap(res,tmp);
        }
        n>>=1;
        mul(a,a,tmp);
        swap(a,tmp);
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n)
    {
        natori p = qpow(n-1);
        
        unsigned int res=0;
        for (int i=0; i<N; i++)
        {
            for (int k=0; k<N; k++)
            {
                res = ((p[k][i]*fir[k])%M + res)%M;
            }
        }
        cout << res << '\n';
    }
}