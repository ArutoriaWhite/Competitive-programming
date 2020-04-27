/*
dp[u][h]
the u-rooted tree, colored h black --> max contribution

for (auto v: adj[u])
{
    for (int j=0; j<h; j++)
    {
        dp[u][h] = max(dp[u][h-j]+dp[v][j]+val)
    }
}

dp[u][h] = max(dp[u][j], dp[u][h-1]+dp[v][1]+val)
*/