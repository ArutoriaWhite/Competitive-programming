#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

int shunfir[N], nifir[N], a[N], b[N], n, m, ans = 1e9, ansp, hav_shun, hav_ni;
int x, y;

signed main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        cin >> a[i] >> b[i];
        if (b[i]) hav_ni = 1;
        else hav_shun = 1;       
    }
    int hd = -1, pref;
    for (int i=m; i>0; i--)
    {
        if (b[i] == 0)
        {
            if (hd == -1)
                hd = i;
            else
                shunfir[i] = pref;
            pref = a[i];
        }
    }
    shunfir[hd] = pref;
    hd = -1;
    for (int i=1; i<=m; i++)
    {
        if (b[i] == 1)
        {
            if (hd == -1)
                hd = i;
            else
                nifir[i] = pref;
            pref = a[i];
        }
    }
    nifir[hd] = pref;
    
    int shun=0, ni=0;
    for (int i=1; i<=m; i++)
    {
        if (i == 1)
        {
            for (int j=2; j<=m; j++)
            {
                if (!b[j]) shun = max(shun, (a[1] - a[j]+n)%n);
                if (b[j]) ni = max(ni, (a[j] - a[1] + n)%n); 
            }
        }
        else
        {
            if (hav_shun) shun += (a[i] - a[i-1] + n)%n;
            if (hav_ni) ni -= (a[i] - a[i-1])%n;
            if (b[i-1] == 1)
                ni += (a[i-1] - nifir[i-1] + n)%n;
            if (b[i] == 0)
                shun -= (shunfir[i] - a[i] + n)%n;
        }
        if (max(shun,ni) < ans)
        {
            ansp = a[i];
            ans = max(shun,ni);
        }
    }

    nifir[hd] = pref;
    cout << ansp << ' ' << ans << '\n';
}
/*
6 4
1 0
3 0
4 1
5 1
*/