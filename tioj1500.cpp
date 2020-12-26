#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e4+10;

int n;
double res = 2e18;
Pii p[N];

double dis (Pii a, Pii b)
{
    double x1 = a.F, x2 = b.F, y1 = a.S, y2 = b.S;
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void f (int l, int r)
{
    if (l>=r) return;
    if (r-l==1)
    {
        res = min(res, dis(p[l],p[r]));
        return;
    }
    int m = (l+r)/2;
    f(l,m);
    f(m+1,r);
    vector<Pii> v;
    for (int i=m; i>=l; i--)
        if (p[m].F - p[i].F > res) break;
        else v.push_back(p[i]);
    for (int i=m+1; i<=r; i++)
        if (p[i].F - p[i].F > res) break;
        else v.push_back(p[i]);
    sort(v.begin(), v.end(), [](Pii a, Pii b){return a.S < b.S;});
    for (int i=0; i<v.size(); i++)
        for (int j=i+1; j<v.size(); j++)
        {
            if (v[j].S - v[i].S > res) break;
            res = min(res, dis(v[i], v[j]));
        }
}

int main()
{
    Eriri
    while (cin >> n)
    {
        res = 2e19;
        for (int i=1; i<=n; i++)
            cin >> p[i].F >> p[i].S;
        sort(p+1, p+1+n);
        f(1,n);
        cout << fixed << setprecision(6) << res << '\n';        
    }
}