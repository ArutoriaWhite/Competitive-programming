#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << endl;
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
const int N = 110;

int a[N][N], vis[N][N], n, m;
vector<pii> path; // dfs and reverse it 
int sh[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int dfs (int i, int j)
{
    if (i<1 || i>n || j<1 || j>m || a[i][j]==1)
        return 0;
    if (a[i][j] == 2)
    {
        path.pb({i,j});
        return 1;
    }

    a[i][j] = 1;

    for (int k=0; k<4; k++)
    {
        int ni = i+sh[k][0];
        int nj = j+sh[k][1];
        if (dfs(ni,nj))
        {
            path.pb({i,j});
            return 1;
        }
    }

    return 0;
}

string L="L",R="R",U="U",D="D";
int _;
int chor=0, cver=0;

void check_hor (int i, int j)
{
    int ni, nj;
    cout << "L" << endl, cin >> ni >> nj;
    if (ni!=i || nj!=j) 
    {
        swap(L,R);
        cout << "R" << endl, cin >> _ >> _;
    }
    chor = 1;
}
void check_ver (int i, int j)
{
    int ni, nj;
    cout << "U" << endl, cin >> ni >> nj;
    if (ni!=i || nj!=j)
    {
        swap(U,D);
        cout << "D" << endl, cin >> _ >> _;
    }
    cver = 1;
}
void print ()
{
    int li=1, lj=1;
    for (auto x: path)
    {
        if (x.ff==1 && x.ss==1) continue;
        int shi = x.ff - li;
        int shj = x.ss - lj;
        if (shi!=0) 
        {
            if (!cver) check_ver(li,lj);
            if (shi>0) cout << D << endl;
            else cout << U << endl;
        }
        if (shj!=0) 
        {
            if (!chor) check_hor(li,lj);
            if (shj>0) cout << R << endl;
            else cout << L << endl;
        }
        cin >> li >> lj;
    }
}

signed main()
{
    cin >> n >> m;
    rep(i,1,n)
    {
        rep(j,1,m)
        {
            char c; cin >> c;
            if (c == '*') a[i][j] = 1;
            else if (c == 'F') a[i][j] = 2;
        }
    }
    dfs(1,1);
    reverse(path.begin(), path.end());
    print();
}