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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, V = 2e4+10, N = 40;

int dp[V][N], res, x, n, w[N];

int f (int v, int i)
{
    if (dp[v][i] == -1)
    {
        if (i == n)
            return v;
        dp[v][i] = f(v,i+1);
        if (v >= w[i])
            dp[v][i] = min(dp[v][i], f(v-w[i],i+1));
    }
    return dp[v][i];
}

int main()
{
    mem(dp,-1);
    cin >> x >> n;
    for (int i=0; i<n; i++)
        cin >> w[i];
    cout << f(x,0) << '\n';
}