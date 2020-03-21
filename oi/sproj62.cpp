#include <bits/stdc++.h>
using namespace std;
const int N = 9;

int sol[N], hor[N], ver[N], blo[3][3];
string mp;

inline void init()
{
    memset(hor,0,sizeof(hor));
    memset(ver,0,sizeof(ver));    
    memset(blo,0,sizeof(blo));
    memset(sol,0,sizeof(sol));
}
inline void add (int x, int y, int k)
{
    hor[y] |= (1<<k), ver[x] |= (1<<k), blo[x/3][y/3] |= (1<<k);
}
inline void del (int x, int y, int k)
{
    hor[y] &= ~(1<<k), ver[x] &= ~(1<<k), blo[x/3][y/3] &= ~(1<<k);
}
inline bool can (int x, int y, int k)
{
    return !((hor[y]&(1<<k)) || (ver[x]&(1<<k)) || (blo[x/3][y/3]&(1<<k)));
}
inline bool build ()
{
    for (int i=0,len=mp.size(); i<len; i++)
        if (mp[i]!='.')
            if (can(i%N,i/N,mp[i]-'0'))
                add(i%N,i/N,mp[i]-'0');
            else return 0;
    return 1;
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
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> mp && mp!="end")
    {
        init();
        if (!build() || !dfs(0)) cout << "No solution.\n";
    }
}s