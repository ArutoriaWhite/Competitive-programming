#include<iostream>
#include<memory.h>
using namespace std;
typedef int (*natori)[8];
typedef int akagi[8][8];
const int N = 8, M = 1000007;
#define int long long

akagi init = 
{
    {1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,1},
};
akagi swit = 
{
    {0,1,0,0,1,0,0,1},
    {1,0,0,0,0,0,1,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0,0},
    {1,0,0,1,0,0,0,0},
    {0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0},
};
int beg[N] = {1};

akagi u, o, p;
inline void muti (natori a, natori b, natori res)
{
    for (int y=0; y<N; y++)
    {
        for (int x=0; x<N; x++)
        {
            res[y][x] = 0;
            for (int k=0; k<N; k++)
                res[y][x] = ((((a[y][k])%M)*(b[k][x])%M)%M+res[y][x])%M;
        }
    }
}
inline natori qpow (int n)
{
    memcpy(u,swit,sizeof(u));
    memcpy(p,init,sizeof(p));
    natori a=u, tmp=o, res=p;
    while (n>0)
    {
        if (n&1)
        {
             muti(a,res,tmp);
             swap(res,tmp);
        }
        muti(a,a,tmp);
        swap(a,tmp);
        n>>=1;
    }
    return res;
}
inline void print(natori ouo)
{
    for (int y=0; y<N; y++)
    {
        for (int x=0; x<N; x++)
            cout << ouo[y][x];
        cout << '\n';
    }
    cout << '\n';
}
signed main()
{
    int T, n, res, k;
    cin >> T;
    while (T--)
    {
        cin >> n;
        natori p = qpow(n);
        for (k=0,res=0; k<N; k++)
            res = (((beg[k])%M*(p[k][0]%M))%M + res)%M;
        cout << res << '\n';
    }
}