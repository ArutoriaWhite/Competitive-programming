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

string cmd;
int n, ad, ap, hp[4][4];
int c, mp;
//pii: row, col
void blast_row (pii tar)
{
    rep(i,1,3)
        hp[tar.ff][i] -= ad*(1+0.2*c);
    c = 0;
}
void blast_col (pii tar)
{
    rep(i,1,3)
        hp[i][tar.ss] -= ad*(1+0.2*c);
    c = 0;
}
void accele (pii tar)
{
    hp[tar.ff][tar.ss] -= ad;
    mp += 20 + 2*c;
    c = 0;
}
void charge (pii tar)
{
    hp[tar.ff][tar.ss] -= ad;
    mp += 2;
    c++;
}
void magia ()
{
    if (mp >= 100)
    {
        mp = 0;
        rep(i,1,3)
            rep(j,1,3)
                hp[i][j] -= ap;
    }
}
pii find_tar()
{
    for (int j=3; j>0; j--)
        for (int i=1; i<=3; i++)
            if (hp[i][j] > 0)
                return {i,j};
}
int clear()
{
    rep(i,1,3)
        rep(j,1,3)
            if (hp[i][j]>0)
                return 0;
    return 1;
}
int handle ()
{
    if (clear()) return 0;
    rep(i,0,n-1)
    {
        pii tar = find_tar();
        if (cmd[i]=='C') charge(tar);
        if (cmd[i]=='A') accele(tar);
        if (cmd[i]=='B') blast_row(tar);
        if (cmd[i]=='b') blast_col(tar);
        magia();
        if (clear())
        {
            return i+1;
        }
    }
    return -1;
}

signed main()
{
    cin >> cmd, n = cmd.size();
    cin >> ad >> ap;
    rep(i,1,3)
        rep(j,1,3)
            cin >> hp[i][j];
    cout << handle() << '\n';
}