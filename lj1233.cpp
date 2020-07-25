#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e3+10;

Pii q[N];
int n;
inline bool cmp (Pii &a, Pii &b){
    return a.F > b.F;
}

inline int lis ()
{
    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        if (v.empty() || v.back()<q[i].S)
            v.push_back(q[i].S);
        else
            *lower_bound(v.begin(),v.end(),q[i].S) = q[i].S;
    }
    return v.size();
}

int main()
{
    Eriri
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> q[i].F >> q[i].S;
    sort(q+1,q+1+n,cmp);
    cout << lis() << '\n';
}