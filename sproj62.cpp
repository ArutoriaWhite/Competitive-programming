#include <bits/stdc++.h>
using namespace std;
const int N = 9;

int hor[N], ver[N], blo[3][3], sol[N*N];
string mp;

inline void init()
{
    memset(hor,0,sizeof(hor));
    memset(ver,0,sizeof(ver));
    memset(blo,0,sizeof(blo));
}
inline void add (int x, int y, int k)
{
    hor[y] |= (1<<k), ver[x] |= (1<<k), blo[x/3][y/3] |= (1<<k);
}
inline void del (int x, int y, int k)
{
    hor[y] &= ~(1<<k), ver[x] &= ~(1<<k), blo[x/3][y/3] &= ~(1<<k);
}
inline void build ()
{
    for (int i=0,len=mp.size(); i<len; i++)
        if (mp[i]!='.')
            add(i%N,i/N,mp[i]-'0');
}
inline bool can (int x, int y, int k)
{
    return !((hor[y]&(1<<k)) || (ver[x]&(1<<k)) || (blo[x/3][y/3]&(1<<k)));
}
bool dfs (int d)
{
    int y=d/N, x=d%N;
    if (d>=N*N)
    {
        for (int i=0; i<N*N; i++) cout << sol[i];
        cout << '\n';
        return 1;
    }
    if (mp[d]!='.')
    {
        sol[d] = mp[d]-'0';
        return dfs(d+1);
    }
    for (int i=1; i<=9; i++)
    {
        if (!can(x,y,i)) continue;
        add(x,y,i), sol[d] = i;
        if (dfs(d+1)) return 1;
        del(x,y,i);
    }
    return 0;
}
int main()
{
    while (cin >> mp && mp!="end")
    {
        init(), build();
        if (!dfs(0)) cout << "No solution.\n";
    }
}