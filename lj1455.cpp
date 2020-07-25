#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10;

int n, m, v, k, cost[N], val[N], acost[N], aval[N], dp[N<<3];
struct Dsu{
    int p[N];
    int find (int x){
        return (p[x]==x? x : p[x]=find(p[x]));
    }
} dsu;

int main() {
    Eriri;
    for (int i=0; i<N; i++)
        dsu.p[i] = i;
    cin >> n >> m >> v;
    for (int i=1; i<=n; i++)
        cin >> cost[i] >> val[i];
    for (int i=1,u,v; i<=m; i++) {
        cin >> u >> v;
        dsu.p[dsu.find(u)] = dsu.find(v);
    }
    for (int i=1; i<=n; i++) {
        if (dsu.p[i] == i) continue;
        cost[dsu.find(i)] += cost[i];
        val[dsu.find(i)] += val[i];
    }
    for (int i=1; i<=n; i++) {
        if (dsu.p[i] != i) continue;
        acost[k] = cost[i];
        aval[k] = val[i];
        k++;
    }
    for (int i=1; i<=n; i++)
        for (int j=v; j>=acost[i-1]; j--)
            dp[j] = max(dp[j], dp[j-acost[i-1]] + aval[i-1]);
    cout << dp[v] << '\n';
}

/*
dp[i][v]
choose from [0,i), max val
 = max( dp[i-1][v], dp[i-1][v-acost[i-1]]+ val[i-1])
for (int i=n; i>0; i--)
    for (int j=w; j>=cost[i-1]; j++)
*/