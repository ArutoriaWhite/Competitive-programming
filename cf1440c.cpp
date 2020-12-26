#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 110;

int a[N][N], n, m, t;

void p (int x, int y){ cout << x << ' ' << y << ' '; }
void print (int i, int j)
{
    if (i<n && j<m)
    {
        p(i,j), p(i,j+1), p(i+1,j), dd;
        p(i,j), p(i,j+1), p(i+1,j+1), dd;
        p(i,j), p(i+1,j), p(i+1,j+1), dd;
    }
    else if (i<n && j>1)
    {
        p(i,j), p(i,j-1), p(i+1,j), dd;
        p(i,j), p(i,j-1), p(i+1,j-1), dd;
        p(i,j), p(i+1,j), p(i+1,j-1), dd;
    }
    else if (i>1 && j>1)
    {
        p(i,j), p(i-1,j), p(i,j-1), dd;
        p(i,j), p(i-1,j), p(i-1,j-1), dd;
        p(i,j), p(i,j-1), p(i-1,j-1), dd;
    }
    else
    {
        p(i,j), p(i-1,j), p(i,j+1), dd;
        p(i,j), p(i-1,j), p(i-1,j+1), dd;
        p(i,j), p(i,j+1), p(i-1,j+1), dd;
    }
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        int k=0;
        cin >> n >> m;
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                char c;
                cin >> c;
                a[i][j] = c=='1';
                if (c=='1') k++;
            }
        }
        cout << k*3 << '\n';
        rep(i,1,n)
            rep(j,1,m)
                if (a[i][j]&1)
                    a[i][j]++, print(i,j);
    }
}