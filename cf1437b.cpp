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

string s;
int n, t;

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int cnt=0;
        for (int i=1; i<n; i++)
        {
            if (s[i] == s[i-1]) cnt++;
        }
        cout << (cnt/2 + cnt%2) << '\n';
    }
}