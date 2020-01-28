#include <iostream>
#include <iomanip>
#define DE cout << " ::"
using namespace std;
const int N = 8;

int w[N][N], k, T;

inline int dfs (int l, int r, int d, int dep)
{
    if (dep==8) return 0;
    int res = -1e9, can = (l|r|d);
    for (int i=0; i<N; i++)
        if (!((1<<i)&can))
            res = max( dfs((l|(1<<i))<<1, (r|(1<<i))>>1, d|(1<<i), dep+1) + w[i][dep], res);
    return res;
}

int main()
{
    cin >> T;
    while (T--)
    {
        for (int y=0; y<N; y++)
            for (int x=N-1; x>=0; x--)
                cin >> w[x][y];
        cout << setw(5) << dfs(0,0,0,0) << '\n';
    }
}