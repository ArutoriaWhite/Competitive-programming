#include<iostream>
#include<vector>
using namespace std;
const int N = 1e3, M = 1e4;

vector<int> G[N];
int q[N], f, r, vis[N], u=0;

inline void init()
{
    f=r=0, u++;
    for (auto v: G)
        v.clear();
}

inline bool BFS (int a, int b)
{
    q[r++] = a;
    while (f<r)
    {
        int u = q[f++];
        for (auto v: G[u])
        {
            if (vis[v]>=u) continue;
            vis[v] = u;
            if (v == b)
                return true;
            else q[r++] = v;         
        }        
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x, y;
    while (cin >> n >> m)
    {
        init();
        for (int i=0; i<m; i++)
        {
            cin >> x >> y;
            G[x].push_back(y);
        }

        cin >> x >> y;
        if (BFS(x,y)) cout << "Yes!!!\n";
        else cout << "No!!!\n";
    }
}
