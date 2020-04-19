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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 150;

int dp[N], res, n, a[N];
// lis[i] = max{ lis[j] | 0<=j<i && j} + 1

inline int lis (int k)
{
    int ans = 0;
    for (int i=0; i<n; i++) dp[i] = 1;
    for (int i=0; i<k; i++)
        for (int j=0; j<i; j++)
            if (a[j] < a[i])
                dp[i] = max(dp[i],dp[j]+1), ans = max(ans,dp[i]);
    return ans;
}
inline int lds (int k)
{
    int ans = 0;
    for (int i=0; i<n; i++) dp[i] = 1;
    for (int i=k; i<n; i++)
        for (int j=k; j<i; j++)
            if (a[j] > a[i])
                dp[i] = max(dp[i],dp[j]+1), ans = max(ans,dp[i]);
    return ans;
}

int main ()
{
    yukari;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    res = INF;
    for (int k=0; k<=n; k++)
        res = min(res, n-lis(k)-lds(k));
    cout << res << '\n';
}