#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 510;

int arr[N][N], G[N][N], mx, my, res;
int fow[N][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};

int main()
{
    yukari;
    cin >> my >> mx;
    for (int y=1; y<=my; y++)
        for (int x=1; x<=mx; x++)
            cin >> arr[x][y];
    for (int x=1; x<=mx; x++)
        for (int y=1; y<=my; y++)
            if (arr[x][y])
                for (int i=0; i<9; i++)
                    G[x+fow[i][0]][y+fow[i][1]] = 1;
    for (int x=1; x<=mx; x++)
        for (int y=1; y<=my; y++)
            if (!G[x][y])
                res++;
    cout << res << '\n';
}