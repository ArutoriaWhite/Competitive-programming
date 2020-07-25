#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10, M = 1e9+7, P = 0xdefaced;

unordered_map<int,int> cnt;
long long ha[N], hb[N], h_base[N];
int k, x, ans, na, nb;
string a, b;

inline void build_hash (string &s, long long h[N])
{
    int n = s.size();
    for (int i=1; i<=n; i++)
        h[i] = (h[i-1]*P + s[i-1])%M;
}
inline int get_hash (long long h[N], int l, int r)
{
    return (h[r] - h[l]*h_base[r-l]%M + M)%M;
}

signed main()
{
    Eriri
    cin >> a >> b >> k >> x;
    na = a.size();
    nb = b.size();

    build_hash(a,ha);
    build_hash(b,hb);
    h_base[0] = 1;
    for (int i=1; i<=max(na,nb); i++)
        h_base[i] = (h_base[i-1]*P)%M;

    for (int i=0; i+k<=na; i++)
    {
        cnt[get_hash(ha,i,i+k)]++;
    }
    for (int i=0; i+k<=nb; i++)
    {
        ans += cnt[get_hash(hb,i,i+k)] > x;
    }
    if (10 * ans > nb - k + 1)
        cout << "copy dog!\n";
    else
        cout << "innocent!\n";
}