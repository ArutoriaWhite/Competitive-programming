#include <bits/stdc++.h>
#include "lib1338.h"
using namespace std;
const int maxN = 1e6+10, K = 30;

long long min_st[K][maxN], gcd_st[K][maxN];

inline long long gcd (long long a, long long b)
{
    long long t;
    if (a>b) swap(a,b);
    while (a>0)
        t = b, b = a, a = t%a;
    return b;
}

void init (int N, long long C[])
{
    // min sparse table
    for (int i=0; i<N; i++)
        min_st[0][i] = C[i];
    for (int j=1; (1<<j)<=N; j++)
        for (int i=0; i+(1<<j)<=N; i++)
            min_st[j][i] = min (min_st[j-1][i], min_st[j-1][i+(1<<(j-1))]);

    // gcd sparse table
    for (int i=0; i<N; i++)
        gcd_st[0][i] = C[i];
    for (int j=1; (1<<j)<=N; j++)
        for (int i=0; i+(1<<j)<=N; i++)
            gcd_st[j][i] = gcd (gcd_st[j-1][i], gcd_st[j-1][i+(1<<(j-1))]);
}

inline long long qmin (int l, int r)
{
    int j; for (j=0; (1<<(j+1))<=(r-l); j++);
    return min( min_st[j][l], min_st[j][r-(1<<j)]);
}

inline long long qgcd (int l, int r)
{
    int j; for (j=0; (1<<(j+1))<=(r-l); j++);
    return gcd( gcd_st[j][l], gcd_st[j][r-(1<<j)]);
}

int query(int L, int R)
{
    return qgcd(L,R)%qmin(L,R)==0;
}