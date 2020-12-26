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
const int N = 1010;

set<int> s[N];
int t, n, k;

int qall()
{
    //cout << "qall: ";
    cout << "? " << n << ' ';
    rep(i,1,n) cout << i << ' ';
    cout << endl;
    int res;
    cin >> res;
    return res;
}
int unlike (int l, int r)
{
    //cout << "unlike: ";
    set<int> ul;
    rep(i,l,r)
        for (auto x: s[i])
            ul.insert(x);//, de(x);
    cout << "? " << ul.size() << ' ';
    for (auto x: ul) cout << x << ' ' ;
    cout << endl;
    int res;
    cin >> res;
    return res;
}
int like (int i)
{
    //cout << "like: ";
    vector<int> lk;
    rep(j,1,n)
        if (s[i].find(j)==s[i].end())
            lk.pb(j);
    cout << "? " << lk.size() << ' ';
    for (auto x: lk) cout << x << ' ';
    cout << endl;
    int res;
    cin >> res;
    return res;
}

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n) s[i].clear();
        rep(i,1,k)
        {
            int c, x;
            cin >> c;
            rep(j,1,c) cin >> x, s[i].insert(x);
        }
        int mx = qall(), l=1, r=k;
        while (l<r)
        {
            int m = (l+r)>>1;
            int q = unlike(l,m);
            if (q>=mx) r = m;
            
            else l = m+1;
        }
        int owo = like(l);
        cout << "! ";
        rep(i,1,k)
        {
            if (i==l) cout << owo << ' ';
            else cout << mx << ' ';
        }
        cout << endl;
        string s;
        cin >> s;
        if (s[0] == 'I') break;
    }
}
/*
a = 1 2 3 4 5 6 7 8 9

*/