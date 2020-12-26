#include "lib1338.h"
#include <algorithm>
using namespace std;
const int maxN = 1e6, K = 20;
typedef long long LL;

LL min_st[K][maxN], gcd_st[K][maxN];

void init(int N, LL C[])
{
    for (int i=0; i<N; i++)
        min_st[0][i] = gcd_st[0][i] = C[i];

    for (int j=1; (1<<j)<=N; j++)
    {
        for (int i=0; i+(1<<j)<=N; i++)
        {
            min_st[j][i] = min( min_st[j-1][i], min_st[j-1][i+(1<<(j-1))]);
            gcd_st[j][i] = __gcd( gcd_st[j-1][i], gcd_st[j-1][i+(1<<(j-1))]);
        }
    }
}

inline LL qmin( int l, int r)
{
    int j = __lg(r-l);
    return min( min_st[j][l], min_st[j][r-(1<<j)]);
}

inline LL qgcd( int l, int r)
{
    int j = __lg(r-l);
    return __gcd( gcd_st[j][l], gcd_st[j][r-(1<<j)]);
}

int query(int L, int R)
{
    return qgcd(L,R)%qmin(L,R)==0;
}