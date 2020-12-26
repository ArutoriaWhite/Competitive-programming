#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 510;

vector<int> row[N];
int ord[N*N], n, m, t;

inline int cmp (vector<int> r1, vector<int> r2)
{
    return ord[r1[1]] < ord[r2[1]];
}

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        rep(i,1,n)
        {
            row[i].resize(m+1);
            rep(j,1,m) cin >> row[i][j];
        }
        rep(i,1,m)
        {
            rep(j,1,n)
            {
                int x;
                cin >> x;
                ord[x] = j;
            }
        }
        sort(row+1, row+1+n, cmp);
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                cout << row[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}