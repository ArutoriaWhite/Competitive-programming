#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 110, M = 20;
int t, n, m, s, k;
int pen[N][M][2], ac[N][M][2], is_rj[N], mn_rank;
int p_sum[N], a_sum[N];

int cmp (int i, int j)
{
    if (a_sum[i] != a_sum[j])
        return a_sum[i] > a_sum[j];
    return p_sum[i] < p_sum[j];
}

void dfs (int i, int k)
{
    if (i > m)
    {
        memset(p_sum,0,sizeof(p_sum));
        memset(a_sum,0,sizeof(a_sum));    	
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                int p = pen[i][j][is_rj[j]];
                int a = ac[i][j][is_rj[j]];
                p_sum[i] += p*a;
                a_sum[i] += a;
            }
        }
        int rk = 1;
        rep(i,2,n) rk += cmp(i,1);
        mn_rank = min(mn_rank, rk);
        return;
    }
    is_rj[i] = 0, dfs(i+1,k);
    if (k) is_rj[i] = 1, dfs(i+1,k-1);
}

signed main()
{
	pui
    cin >> t;
    while (t--)
    {
        // init
        memset(pen,0,sizeof(pen));
        memset(ac,0,sizeof(ac));
        mn_rank = 9e18;
        
        cin >> n >> m >> s >> k;
        // 求 ac[i][j][k], 在有或沒有 rejudge 的情況下(k)，第 i 隊是否 AC 第 j 題
        // 求 pen[i][j][k], 在有或沒有 rejudge 的情況下(k)，第 i 隊若 AC 第 j 題則罰時多少
        rep(i,1,s)
        {
            int t, g, p, a, b;
            cin >> t >> g >> p >> a >> b;
            g++, p++;
            if (!ac[g][p][0])
            {
                pen[g][p][0] += 20;
                if (a) pen[g][p][0] += t, ac[g][p][0] = 1;
            }
            if (!ac[g][p][1])
            {
                pen[g][p][1] += 20;
                if (b) pen[g][p][1] += t, ac[g][p][1] = 1;
            }
        }
        dfs(0,k);
        cout << mn_rank << endl;
    }
}