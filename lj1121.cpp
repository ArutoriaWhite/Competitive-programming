#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

int n;
long long dp[N][3], dp2[N], pre[N], mpre[N], suf[N], msuf[N];
long long res, m_fir_sec, a[N];

inline void init()
{
    res = INT_MIN;
    for (int i=1; i<=n; i++)
    {
        dp[i][1] = INT_MIN;
        dp[i][2] = INT_MIN;
        dp2[i] = INT_MIN;
        mpre[i] = INT_MIN;
        msuf[i] = INT_MIN;
    }
}

void con()
{
    mpre[1] = pre[1] = a[1];
    for (int i=2; i<=n; i++)
        pre[i] = pre[i-1] + a[i], mpre[i] = max( mpre[i-1], pre[i]);
    msuf[n] = suf[n] = a[n];
    for (int i=n-1; i>=1; i--)
        suf[i] = suf[i+1] + a[i], msuf[i] = max( msuf[i+1], suf[i]);
    for (int i=2; i<n; i++)
    {
        dp2[i] = max( dp2[i-1] + a[i], mpre[i-1] + a[i]);
        res = max( res, dp2[i] + msuf[i+1] );
    }
}
void incon()
{
    dp[1][1] = a[1];
    m_fir_sec = a[1];
    for (int i=2; i<=n; i++)
    {
        dp[i][1] = max( dp[i-1][1] + a[i], a[i]);
        dp[i][2] = max( dp[i-1][2] + a[i], a[i] + m_fir_sec);
        res = max( res, dp[i][2] );
        m_fir_sec = max( m_fir_sec, dp[i][1] );
    }
}

int main()
{
    Eriri
    init();
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    con();
    incon();
    cout << res << '\n';
}